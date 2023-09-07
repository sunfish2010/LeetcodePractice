/*
 * @lc app=leetcode id=703 lang=cpp
 * @lcpr version=21913
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;
class KthLargest {
   public:
    KthLargest(int k, vector<int>& nums) : k_(k) {
        int n = min(k, static_cast<int>(nums.size()));
        if (n == 0) {
            return;
        }
        data = priority_queue(nums.begin(), nums.begin() + n, std::greater<int>());
        for (int i = k; i < nums.size(); ++i) {
            if (nums[i] > data.top()) {
                data.pop();
                data.push(nums[i]);
            }
        }
    }

    int add(int val) {
        if (data.size() < k_) {
            data.push(val);
        } else if (val > data.top()) {
            data.pop();
            data.push(val);
        }
        return data.top();
    }

   private:
    priority_queue<int, vector<int>, std::greater<int>> data;
    int k_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
