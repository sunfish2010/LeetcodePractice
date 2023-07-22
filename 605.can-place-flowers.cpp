/*
 * @lc app=leetcode id=605 lang=cpp
 * @lcpr version=21909
 *
 * [605] Can Place Flowers
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
   public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int num_beds = flowerbed.size();
        for (int i = 0; i < num_beds; i = i + 2) {
            if (!flowerbed[i]) {
                bool can_plant = true;
                can_plant &= (i == 0) || !flowerbed[i - 1];
                can_plant &= (i == num_beds - 1) || !flowerbed[i + 1];
                if (can_plant) {
                    flowerbed[i] = 1;
                    --n;
                    if (n <= 0) {
                        return true;
                    }
                }
            }
        }
        // For odd number of flowers, we may omit the last spot.
        if (num_beds > 2 && !flowerbed[num_beds - 1] && !flowerbed[num_beds - 2]) {
            --n;
        }
        return n <= 0;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,0,0,0,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,0,0,0,1]\n2\n
// @lcpr case=end

 */
