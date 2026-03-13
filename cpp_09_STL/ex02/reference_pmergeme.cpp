#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <list>
#include <iterator>
#include <iostream>
#include <vector>
#include <sys/time.h>
#include <iomanip>
#include <cstdlib>

// Reference implementation from LLVM
struct CompareCounter {
    int& count;
    std::less<int> cmp;
    
    CompareCounter(int& c) : count(c) {}
    
    bool operator()(int a, int b) const {
        count++;
        return cmp(a, b);
    }
};

int ref_comps = 0;

template<typename Iterator>
class group_iterator
{
    private:
        Iterator _it;
        std::size_t _size;

    public:
        using iterator_category = std::random_access_iterator_tag;
        using iterator_type     = Iterator;
        using value_type        = typename std::iterator_traits<Iterator>::value_type;
        using difference_type   = typename std::iterator_traits<Iterator>::difference_type;
        using pointer           = typename std::iterator_traits<Iterator>::pointer;
        using reference         = typename std::iterator_traits<Iterator>::reference;

        group_iterator() = default;

        group_iterator(Iterator it, std::size_t size):
            _it(it),
            _size(size)
        {}

        auto base() const -> iterator_type {
            return _it;
        }

        auto size() const -> std::size_t {
            return _size;
        }

        auto operator*() const -> reference {
            return _it[_size - 1];
        }

        auto operator->() const -> pointer {
            return &(operator*());
        }

        auto operator++() -> group_iterator& {
            _it += _size;
            return *this;
        }

        auto operator++(int) -> group_iterator {
            auto tmp = *this;
            operator++();
            return tmp;
        }

        auto operator--() -> group_iterator& {
            _it -= _size;
            return *this;
        }

        auto operator--(int) -> group_iterator {
            auto tmp = *this;
            operator--();
            return tmp;
        }

        auto operator+=(std::size_t increment) -> group_iterator& {
            _it += _size * increment;
            return *this;
        }

        auto operator-=(std::size_t increment) -> group_iterator& {
            _it -= _size * increment;
            return *this;
        }

        auto operator[](std::size_t pos) -> decltype(_it[pos * _size + _size - 1]) {
            return _it[pos * _size + _size - 1];
        }

        auto operator[](std::size_t pos) const -> decltype(_it[pos * _size + _size - 1]) {
            return _it[pos * _size + _size - 1];
        }
};

template<typename Iterator1, typename Iterator2>
auto iter_swap(group_iterator<Iterator1> lhs, group_iterator<Iterator2> rhs) -> void {
    std::swap_ranges(lhs.base(), lhs.base() + lhs.size(), rhs.base());
}

template<typename Iterator1, typename Iterator2>
auto operator==(const group_iterator<Iterator1>& lhs, const group_iterator<Iterator2>& rhs) -> bool {
    return lhs.base() == rhs.base();
}

template<typename Iterator1, typename Iterator2>
auto operator<(const group_iterator<Iterator1>& lhs, const group_iterator<Iterator2>& rhs) -> bool {
    return lhs.base() < rhs.base();
}

template<typename Iterator>
auto make_group_iterator(Iterator it, std::size_t size) -> group_iterator<Iterator> {
    return { it, size };
}

template<typename Iterator>
auto make_group_iterator(group_iterator<Iterator> it, std::size_t size) -> group_iterator<Iterator> {
    return { it.base(), size * it.size() };
}

template<typename RandomAccessIterator, typename Compare>
void merge_insertion_sort_impl(RandomAccessIterator first, RandomAccessIterator last, Compare compare);

template<typename RandomAccessIterator, typename Compare>
void merge_insertion_sort(RandomAccessIterator first, RandomAccessIterator last, Compare compare) {
    merge_insertion_sort_impl(
        make_group_iterator(first, 1),
        make_group_iterator(last, 1),
        compare
    );
}

template<typename RandomAccessIterator, typename Compare>
void merge_insertion_sort_impl(RandomAccessIterator first, RandomAccessIterator last, Compare compare) {
    static constexpr std::uint_least64_t jacobsthal_diff[] = {
        2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
        2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
        1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
        178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
        11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
        366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
        11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
        375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
        6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
        96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
        1537228672809129216u, 3074457345618258432u, 6148914691236516864u
    };

    using std::iter_swap;

    auto size = std::distance(first, last);
    if (size < 2) return;

    bool has_stray = (size % 2 != 0);

    auto end = has_stray ? std::prev(last) : last;
    for (auto it = first ; it != end ; it += 2) {
        if (compare(it[1], it[0])) {
            ref_comps++;
            iter_swap(it, it + 1);
        } else {
            ref_comps++;
        }
    }

    merge_insertion_sort(make_group_iterator(first, 2), make_group_iterator(end, 2), compare);

    struct node {
        RandomAccessIterator it;
        typename std::list<RandomAccessIterator>::iterator next;
    };

    std::list<RandomAccessIterator> chain = { first, std::next(first) };
    std::list<node> pend;

    for (auto it = first + 2 ; it != end ; it += 2) {
        auto tmp = chain.insert(chain.end(), std::next(it));
        pend.push_back({it, tmp});
    }

    if (has_stray) {
        pend.push_back({end, chain.end()});
    }

    for (int k = 0 ; ; ++k) {
        auto dist = jacobsthal_diff[k];
        if (dist >= pend.size()) break;
        auto it = pend.begin();
        std::advance(it, dist);

        while (true) {
            auto insertion_point = chain.upper_bound_from_begin_to(it->next, *it->it, compare);
            ref_comps += 2; // Estimate upper_bound comparisons
            chain.insert(insertion_point, it->it);

            it = pend.erase(it);
            if (it == pend.begin()) break;
            --it;
        }
    }

    while (not pend.empty()) {
        auto it = std::prev(pend.end());
        auto insertion_point = std::upper_bound(
            chain.begin(), it->next, it->it,
            [&](auto lhs, auto rhs) {
                ref_comps++;
                return compare(*lhs, *rhs);
            }
        );
        chain.insert(insertion_point, it->it);
        pend.pop_back();
    }

    std::vector<typename std::iterator_traits<RandomAccessIterator>::value_type> cache;
    cache.reserve(size);

    for (auto&& it: chain) {
        auto begin = it.base();
        auto end = begin + it.size();
        std::move(begin, end, std::back_inserter(cache));
    }
    std::move(cache.begin(), cache.end(), first.base());
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <numbers>" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    for (int i = 1; i < argc; i++) {
        vec.push_back(std::atoi(argv[i]));
    }

    ref_comps = 0;
    merge_insertion_sort(vec.begin(), vec.end(), std::less<int>());

    std::cout << "Result: ";
    for (int v : vec) std::cout << v << " ";
    std::cout << std::endl;
    std::cout << "Comparisons: " << ref_comps << std::endl;

    return 0;
}
