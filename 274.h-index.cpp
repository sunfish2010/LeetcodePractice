/*
 * @lc app=leetcode id=274 lang=cpp
 * @lcpr version=21909
 *
 * [274] H-Index
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int num_papers = citations.size();

        for (int i = 0; i < num_papers; ++i) {
            if (citations[i] >= num_papers - i) {
                return num_papers - i;
            }
        }
        return 0;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,0,6,1,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,1]\n
// @lcpr case=end

 */
