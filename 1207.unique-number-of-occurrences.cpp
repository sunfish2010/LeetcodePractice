/*
 * @lc app=leetcode id=1207 lang=cpp
 * @lcpr version=21912
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> num_freq;
        for (const auto& num : arr) {
            num_freq[num]++;
        }
        unordered_set<int> occurances;
        for (const auto& [num, freq] : num_freq) {
            if (occurances.count(freq)) {
                return false;
            }
            occurances.insert(freq);
        }
        return occurances.size() == num_freq.size();
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,2,1,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// [-3,0,1,-3,1,1,1,-3,10,0]\n
// @lcpr case=end

 */
