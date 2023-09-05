/*
 * @lc app=leetcode id=974 lang=cpp
 * @lcpr version=21913
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        unordered_map<int, int> prefix_sum;
        for (const auto& num : nums) {
            sum += num;
            int modu = sum % k;
            count += modu == 0;
            modu = modu < 0 ? modu + k : modu;
            count += prefix_sum[modu];
            prefix_sum[modu]++;
        }
        return count;
        /*
        Can be modified to use a vector.
        vector<int> modGroups(k);
        modGroups[0] = 1;

        prefixMod = (prefixMod + num % k + k) % k;
        */
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,5,0,-2,-3,1]\n5\n
// @lcpr case=end

// @lcpr case=start
// [5]\n9\n
// @lcpr case=end

 */
