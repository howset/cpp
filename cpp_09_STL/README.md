## Notes:
### Ex00
- container: map

### Ex01
- container: stack but use the underlying conatiner as list
- what is while (iss >> token)
- evaluation table for "1 2 * 2 / 2 * 2 4 - +"

| Token | Stack State | Action                               |
|-------|-------------|--------------------------------------|
| 1     | [1]         | Push 1 onto stack                    |
| 2     | [1, 2]      | Push 2 onto stack                    |
| *     | [2]         | Pop 2 and 1 → 1 * 2 = 2 → Push 2     |
| 2     | [2, 2]      | Push 2 onto stack                    |
| /     | [1]         | Pop 2 and 2 → 2 / 2 = 1 → Push 1     |
| 2     | [1, 2]      | Push 2 onto stack                    |
| *     | [2]         | Pop 2 and 1 → 1 * 2 = 2 → Push 2     |
| 2     | [2, 2]      | Push 2 onto stack                    |
| 4     | [2, 2, 4]   | Push 4 onto stack                    |
| -     | [2, -2]     | Pop 4 and 2 → 2 - 4 = -2 → Push -2   |
| +     | [0]         | Pop -2 and 2 → 2 + (-2) = 0 → Push 0 |

### Ex02
- container: vector, deque
- Algorithm:
	1. pairing of numbers, leave straggler
	2. sort the winners of the pair, keeping the index of each loser pair
	3. insert losers following jacobsthal sequence
- Sources:
	- https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91
	- https://medium.com/@mohammad.ali.ibrahim.525/ford-johnson-algorithm-merge-insertion-4b024f0c3d42
	- https://github.com/alx-sch/CPP_Glossary?tab=readme-ov-file#ford-johnson-algorithm
	- https://github.com/leske42/CPP09
	- https://stackoverflow.com/questions/27751132/how-does-merge-insertion-sort-work
	- https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort

| n  | ⌈log​(n!)⌉ | F(n) |
|----|-----------|------|
| 1  | 0         | 0    |
| 2  | 1         | 1    |
| 3  | 3         | 3    |
| 4  | 5         | 5    |
| 5  | 7         | 7    |
| 6  | 10        | 10   |
| 7  | 13        | 13   |
| 8  | 16        | 16   |
| 9  | 19        | 19   |
| 10 | 22        | 22   |
| 11 | 26        | 26   |
| 12 | 29        | 30   |
| 13 | 33        | 34   |
| 14 | 37        | 38   |
| 15 | 41        | 42   |
| 16 | 45        | 46   |
| 17 | 49        | 50   |
| 18 | 53        | 54   |
| 19 | 57        | 58   |
| 20 | 62        | 62   |
| 21 | 66        | 66   |
| 22 | 70        | 71   |
| 23 | 75        | 76   |
| 24 | 80        | 81   |
| 25 | 84        | 86   |
| 26 | 89        | 91   |
| 27 | 94        | 96   |
| 28 | 98        | 101  |
| 29 | 103       | 106  |
| 30 | 108       | 111  |
| 31 | 113       | 116  |
| 32 | 118       | 121  |
| 33 | 123       | 126  |


Assume:

pairs are (small, big):
p0=(2,9)
p1=(5,7)
p2=(1,9)
p3=(3,4)
Sorted bigger = [4,7,9,9]
Initial used = [F,F,F,F]
Initial pendChain = []
w	bigger[w]	matched p	appended pairs[p].first	used after	pendChain after
0	4	p3	3	[F,F,F,T]	[3]
1	7	p1	5	[F,T,F,T]	[3,5]
2	9	p0	2	[T,T,F,T]	[3,5,2]
3	9	p2	1	[T,T,T,T]	[3,5,2,1]
Notice at w=2 and w=3, both values are 9.
Without used, both could accidentally match p0. With used, p0 is taken first, then p2.

please explain why my output varies between 6 to 8 comparisons?

The variation is due to differences in the binary search phase, which is key to the Ford-Johnson algorithm.
Here's why the comparison count varies even with the same input size:

For 5 elements:

Pairing phase — Always 2 comparisons (comparing 2 pairs)
Recursive sort — Always 1 comparison (sorting the 2 "bigger" elements)
Binary search insertions — Variable (2-4 comparisons depending on where elements fall)
Straggler insertion — Variable (1-2 comparisons)
Total: 2 + 1 + (2-4) + (1-2) = 6 to 8 comparisons

The binary search comparison count depends on how many times the search space gets halved before finding the insertion point. This varies based on:

Element values and their relative order — Whether they're small, large, or middle-range
Where they fall in the mainChain — Elements at boundaries need fewer comparisons than middle values
Example:

If a pending element is the smallest, binary search finds it quickly (fewer comparisons)
If it's in the middle range, binary search needs more halvings (more comparisons)
This is completely normal behavior — it demonstrates that the Ford-Johnson algorithm has a variable (not fixed) number of comparisons, even for the same input size, based on the actual element values and their distribution.


Ford-Johnson Sort for 8 Elements
Input: [8, 7, 6, 5, 4, 3, 2, 1]
1. Pairing (4 comparisons)
(8, 7): Compare → 8 > 7 → bigger: 8, pending: 7
(6, 5): Compare → 6 > 5 → bigger: 6, pending: 5
(4, 3): Compare → 4 > 3 → bigger: 4, pending: 3
(2, 1): Compare → 2 > 1 → bigger: 2, pending: 1
Bigger chain: [8, 6, 4, 2]
Pending chain: [7, 5, 3, 1]
Comparisons so far: 4

2. Recursively sort bigger chain ([8, 6, 4, 2]) — see previous answer for details
Pairing (2 comparisons):
(8, 6): Compare → 8 > 6 → bigger: 8, pending: 6
(4, 2): Compare → 4 > 2 → bigger: 4, pending: 2
Bigger chain: [8, 4]
Pending chain: [6, 2]
Comparisons so far: 6

Recursively sort [8, 4]:
(8, 4): Compare → 8 > 4 → bigger: 8, pending: 4
Comparisons so far: 7

Recursively sort [8]: no comparison

Recursively sort [4]: no comparison

Main chain: [4, 8]

Insert pending [6, 2] into [4, 8]:
Insert 6: Compare 4 < 6 → true, insert at position 1
Comparisons so far: 8

Insert 2: Compare 4 < 2 → false, insert at position 0
Comparisons so far: 9

Sorted bigger chain: [2, 4, 6, 8]
Total comparisons for this recursion: 5

3. Reorder pending chain to match sorted bigger chain
For each bigger element, find its original pending pair:
2 → 1
4 → 3
6 → 5
8 → 7
Pending chain reordered: [1, 3, 5, 7]

4. Build main chain
Start with first pending: 1
Add sorted bigger chain: 2, 4, 6, 8
Main chain: [1, 2, 4, 6, 8]

5. Insert remaining pending elements ([3, 5, 7]) using Jacobsthal order
Jacobsthal order for 4 elements: [3, 2, 1] (indices)
Insert 7 (index 3):

Bound: up to position 5 (full chain)
Binary search in [1, 2, 4, 6, 8]:
Compare 4 < 7 → true (position 3)
Compare 6 < 7 → true (position 4)
Compare 8 < 7 → false (position 4)
Insert at position 4
Comparisons: 3
Insert 5 (index 2):

Bound: up to position 4
Binary search in [1, 2, 4, 6, 7, 8]:
Compare 4 < 5 → true (position 3)
Compare 6 < 5 → false (position 3)
Insert at position 3
Comparisons: 2
Insert 3 (index 1):

Bound: up to position 3
Binary search in [1, 2, 4, 5, 6, 7, 8]:
Compare 2 < 3 → true (position 1)
Compare 4 < 3 → false (position 1)
Insert at position 1
Comparisons: 2
Total insertion comparisons: 7

6. Final sorted chain
[1, 2, 3, 4, 5, 6, 7, 8]

7. Total comparisons
Pairing: 4
Recursion: 5
Insertion: 7
Total: 16
Summary Table

Step	Comparisons
Pairing	4
Recursion	5
Insertion	7
Total	16