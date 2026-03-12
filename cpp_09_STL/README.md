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
