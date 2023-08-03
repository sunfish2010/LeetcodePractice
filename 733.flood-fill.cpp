/*
 * @lc app=leetcode id=733 lang=cpp
 * @lcpr version=21912
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
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
