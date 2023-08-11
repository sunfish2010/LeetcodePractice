/*
 * @lc app=leetcode id=399 lang=cpp
 * @lcpr version=21913
 *
 * [399] Evaluate Division
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Dividend, divisor
        unordered_map<string, unordered_map<string, double>> connectivity;
        for (int i = 0; i < equations.size(); ++i) {
            const auto& equation = equations[i];
            connectivity[equation[0]][equation[1]] = values[i];
            connectivity[equation[1]][equation[0]] = 1.0 / values[i];
        }
        vector<double> results;
        for (const auto& query : queries) {
            const auto& dividend = query[0];
            const auto& divisor = query[1];
            if (connectivity.count(dividend) == 0 || connectivity.count(divisor) == 0) {
                results.push_back(-1.0);
                continue;
            } else if (dividend == divisor) {
                results.push_back(1.0);
            } else {
                unordered_set<string> visited;
                results.push_back(dfs(connectivity, dividend, divisor, 1, visited));
            }
        }
        return results;
    }

   private:
    double dfs(const unordered_map<string, unordered_map<string, double>>& connectivity, const string& dividend, const string& divisor, double curr_result, unordered_set<string>& visited) {
        visited.insert(dividend);
        double result = -1;
        if (connectivity.at(dividend).count(divisor) > 0) {
            return connectivity.at(dividend).at(divisor) * curr_result;
        } else {
            for (const auto& [mid_divisor, value] : connectivity.at(dividend)) {
                if (visited.find(mid_divisor) == visited.end()) {
                    result = dfs(connectivity, mid_divisor, divisor, curr_result * value, visited);
                    if (result != -1) {
                        break;
                    }
                }
            }
        }
        visited.erase(dividend);
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [["a","b"],["b","c"]]\n[2.0,3.0]\n[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]\n
// @lcpr case=end

// @lcpr case=start
// [["a","b"],["b","c"],["bc","cd"]]\n[1.5,2.5,5.0]\n[["a","c"],["c","b"],["bc","cd"],["cd","bc"]]\n
// @lcpr case=end

// @lcpr case=start
// [["a","b"]]\n[0.5]\n[["a","b"],["b","a"],["a","c"],["x","y"]]\n
// @lcpr case=end

 */
