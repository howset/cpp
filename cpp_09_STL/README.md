## Notes:
### Ex00
- container: map
- cleanups --> make main follow the same form as ex01 & 02 with try catch block

### Ex01
- container: stack
- what to do with ''?
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
- 
- Algorithm:
	1. pairing of numbers, leave straggler
	2. sort the winners of the pair, keeping the index of each loser pair
	3. insert losers following jacobsthal sequence