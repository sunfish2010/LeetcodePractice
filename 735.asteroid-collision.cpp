/*
 * @lc app=leetcode id=735 lang=cpp
 * @lcpr version=21912
 *
 * [735] Asteroid Collision
 */

// @lc code=start
#include <stack>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> left_over;
        left_over.reserve(asteroids.size());
        for (const auto& asteroid : asteroids) {
            if (left_over.empty() || left_over.back() < 0 && asteroid > 0) {
                left_over.push_back(asteroid);
            } else {
                bool destroyed = false;
                while (!left_over.empty() && left_over.back() > 0 && asteroid < 0) {
                    const auto top_ast = left_over.back();
                    if (abs(top_ast) < abs(asteroid)) {
                        left_over.pop_back();
                    } else {
                        if (abs(top_ast) == abs(asteroid)) {
                            left_over.pop_back();
                        }
                        destroyed = true;
                        break;
                    }
                }
                if (!destroyed) {
                    left_over.push_back(asteroid);
                }
            }
        }
        return left_over;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [5,10,-5]\n
// @lcpr case=end

// @lcpr case=start
// [8,-8]\n
// @lcpr case=end

// @lcpr case=start
// [10,2,-5]\n
// @lcpr case=end

 */
