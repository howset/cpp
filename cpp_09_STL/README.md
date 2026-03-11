## Notes:
### Ex00
- container: map

### Ex01
- how to use getline?
- container: stack
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
- how to use getline?
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
	
