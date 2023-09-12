/*
 * @lc app=leetcode id=5 lang=cpp
 * @lcpr version=21913
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        int max_length = 1;
        int mid = 0;
        int max_length_left = 0;
        while (mid < n) {
            int left = mid;
            int right = mid;
            // Middle duplicate elements.
            while (right < n - 1 && s[right + 1] == s[right]) {
                right++;
            }
            // The next valid middle must be at least right + 1 now,
            // since otherwise s[right + 1] will be the same as s[right] or it can form a palindrom at s[left] and s[right],
            mid = right + 1;
            // Which we check now.
            while (right < n - 1 && left > 0 && s[left - 1] == s[right + 1]) {
                left--;
                right++;
            }
            if (right - left + 1 > max_length) {
                max_length = right - left + 1;
                max_length_left = left;
            }
        }
        return s.substr(max_length_left, max_length);
    }
};
#include <queue>
class Solution {
   public:
    int minimumMoves(vector<vector<int>>& grid) {
        num_rows = grid.size();
        num_cols = grid[0].size();
        vector<vector<int>> dist(num_rows, vector<int>(num_cols, INT_MAX));
        const static vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int moves = 0;
        for (int i = 0; i < num_rows; ++i) {
            for (int j = 0; j < num_cols; ++j) {
                if (grid[i][j] == 0) {
                    vector<vector<int>> visited(num_rows, vector<int>(num_cols, false));
                    queue<pair<int, int>> cells;
                    cells.push({i, j});
                    visited[i][j] = true;
                    int curr_dist = -1;
                    while (!cells.empty()) {
                        curr_dist += 1;
                        int num_cells = cells.size();
                        for (int i = 0; i < num_cells; ++i) {
                            int row = cells.front().first;
                            int col = cells.front().second;
                            if (grid[row][col] > 1) {
                                moves += curr_dist;
                                grid[row][col] -= 1;
                            }
                            cells.pop();
                            for (const auto& dir : dirs) {
                                int next_row = row + dir[0];
                                int next_col = col + dir[1];
                                if (next_row >= 0 && next_row < num_rows && next_col < num_cols && next_col >= 0 && !visited[next_row][next_col]) {
                                    visited[next_row][next_col] = true;
                                    cells.push({next_row, next_col});
                                }
                            }
                        }
                    }
                }
            }
        }
        return moves;
    }

   private:
    int num_rows, num_cols;
};
// Another solution checking on even odd length.
/*
    string longestPalindrome(string s) {
        int end = 0;
        int start = 0;
        for(int i = 0; i < s.length(); ++i){
            int odd_len = longest_palindrome_substring(s, i, i);
            int even_len = longest_palindrome_substring(s, i, i+1);
            int curr_max_len = max(odd_len, even_len);
            if(curr_max_len > end-start + 1){
                end = i + curr_max_len/2;
                start = i - (curr_max_len-1)/2;
            }
        }
        return s.substr(start, end-start+1);
    }

    int longest_palindrome_substring(const string&s, int left, int right){
        while(left >= 0 && right < s.length() && s[left] == s[right]){
                 left--;
                ++right;
        }
        return right - left - 1;

*/
// @lc code=end

/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */
