/*
 * @lc app=leetcode id=14 lang=cpp
 * @lcpr version=21913
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        int min_length = strs[0].size();
        for (const auto& str : strs) {
            min_length = min(int(str.size()), min_length);
        }
        int low = 0;
        int high = min_length;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (is_common_prefix(strs, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return strs[0].substr(0, high);
    }

   private:
    bool is_common_prefix(const vector<string>& strs, int length) {
        string prefix = strs[0].substr(0, length);
        for (int i = 1; i < strs.size(); ++i) {
            if (strs[i].find(prefix) != 0) {
                return false;
            }
        }
        return true;
    }
};

/*

    sort(strs.begin(), strs.end());
    int length = min(strs.front().size(), strs.back().size());
    string ans;
    for(int i = 0; i < length;++i){
        if(strs.front()[i] != strs.back()[i]){
            break;
        }else{
            ans += strs.front()[i];
        }
    }
    return ans;
*/
// @lc code=end

/*
// @lcpr case=start
// ["flower","flow","flight"]\n
// @lcpr case=end

// @lcpr case=start
// ["dog","racecar","car"]\n
// @lcpr case=end

 */
