/*
 * @lc app=leetcode id=733 lang=cpp
 * @lcpr version=21912
 *
 * [733] Flood Fill
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color){
            return image;
        }
        static vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int num_rows = image.size();
        int num_cols = image[0].size();
        int orig = image[sr][sc];
         image[sr][sc] = color;
        vector<vector<int>>to_visit = {{sr, sc}};
        while(!to_visit.empty()){
            int row = to_visit.back()[0];
            int col = to_visit.back()[1];
            to_visit.pop_back();
            for(const auto&dir: dirs){
                int next_row = row + dir[0];
                int next_col = col + dir[1];
                if(next_col >=0 && next_col < num_cols && next_row >=0 && next_row < num_rows && image[next_row][next_col] == orig){
                    image[next_row][next_col] = color;
                    to_visit.push_back({next_row, next_col});
                }
            }
        }
        return image;

    }
};

/*

Python


def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
    if color == image[sr][sc]:
        return image
    coords = [[sr, sc]]
    num_rows = len(image)
    num_cols = len(image[0])
    dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]
    original_color = image[sr][sc]
    image[sr][sc] = color
    while len(coords) > 0:
        row, col = coords.pop()
        new_coords = [[row + dir[0], col + dir[1]] for dir in dirs]
        new_coords = [new_coord for new_coord in new_coords if (0 <= new_coord[0] < num_rows \
                                                                and 0 <= new_coord[1] < num_cols \
                                                                and image[new_coord[0]][
                                                                    new_coord[1]] == original_color)]
        for new_coord in new_coords:
            image[new_coord[0]][new_coord[1]] = color
        coords.extend(new_coords)

    return image

*/
// @lc code=end

/*
// @lcpr case=start
// [[1,1,1],[1,1,0],[1,0,1]]\n1\n1\n2\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0],[0,0,0]]\n0\n0\n0\n
// @lcpr case=end

 */
