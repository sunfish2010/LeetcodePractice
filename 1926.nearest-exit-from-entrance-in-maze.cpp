/*
 * @lc app=leetcode id=1926 lang=cpp
 * @lcpr version=21912
 *
 * [1926] Nearest Exit from Entrance in Maze
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;

/*
Somehow doesn't pass leetcode time limit if use lamda function to test if is valid cell or is exit.
*/
class Solution {
   public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        const int num_rows = maze.size();
        const int num_cols = maze[0].size();

        static const vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        queue<vector<int>> empty_cells;
        empty_cells.push(entrance);
        maze[entrance[0]][entrance[1]] = '+';
        int step = 0;
        while (!empty_cells.empty()) {
            int num_valid_cells = empty_cells.size();
            for (int i = 0; i < num_valid_cells; ++i) {
                const int y = empty_cells.front()[0];
                const int x = empty_cells.front()[1];
                empty_cells.pop();

                for (const auto& dir : dirs) {
                    int new_y = dir[0] + y;
                    int new_x = dir[1] + x;
                    // Valid cell.
                    if (new_x >= 0 && new_x < num_cols && new_y >= 0 && new_y < num_rows && maze[new_y][new_x] == '.') {
                        // Is exit.
                        if (new_x == 0 || new_y == 0 || new_x == num_cols - 1 || new_y == num_rows - 1) {
                            return step + 1;
                        }
                        // Mark cell as visited.
                        maze[new_y][new_x] = '+';
                        empty_cells.push({new_y, new_x});
                    }
                }
            }
            step++;
        }
        return -1;
    }
};

/*
Python 3

from typing import  List
from collections import deque

class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        rows= len(maze)
        cols = len(maze[0])
        dirs = [[0, -1], [0, 1], [1, 0], [-1, 0]]

        empty_cells = deque()
        empty_cells.append(entrance)

        maze[entrance[0]][entrance[1]] = '+'
        step = 0
        while empty_cells:
            num_valid_cells = len(empty_cells)
            for i in range(num_valid_cells):
                y, x = empty_cells.popleft()
                for dir in dirs:
                    new_y = y + dir[0]
                    new_x = x + dir[1]
                    if 0 <= new_x < cols and 0 <= new_y < rows and maze[new_y][new_x] == '.':
                        if new_x == 0 or new_y == 0 or new_y == rows - 1 or new_x == cols - 1:
                            return step + 1
                        maze[new_y][new_x] = '+'
                        empty_cells.append([new_y, new_x])
            step += 1

        return -1


if __name__ == '__main__':
    maze = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
    solution = Solution()
    print(solution.nearestExit(maze))
*/
// @lc code=end

/*
// @lcpr case=start
// [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]]\n[1,2]\n
// @lcpr case=end

// @lcpr case=start
// [["+","+","+"],[".",".","."],["+","+","+"]]\n[1,0]\n
// @lcpr case=end

// @lcpr case=start
// [[".","+"]]\n[0,0]\n
// @lcpr case=end

 */
