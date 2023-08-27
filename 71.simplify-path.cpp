/*
 * @lc app=leetcode id=71 lang=cpp
 * @lcpr version=21913
 *
 * [71] Simplify Path
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    string simplifyPath(string path) {
        string curr;
        int i = 0;
        vector<string> paths;
        while (i < path.size()) {
            if (path[i] == '/') {
                if (!curr.empty()) {
                    if (curr == "..") {
                        if (!paths.empty()) {
                            paths.pop_back();
                        }
                    } else if (curr != ".") {
                        paths.push_back(curr);
                    }
                    curr.clear();
                }

                ++i;
            } else {
                curr += path[i++];
            }
        }
        if (!curr.empty()) {
            if (curr == "..") {
                if (!paths.empty()) {
                    paths.pop_back();
                }
            } else if (curr != ".") {
                paths.push_back(curr);
            }
        }
        string simplied_path = "/";
        for (const auto& c : paths) {
            simplied_path += c + "/";
        }
        if (simplied_path.size() > 1) {
            simplied_path.pop_back();
        }

        return simplied_path;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "/home/"\n
// @lcpr case=end

// @lcpr case=start
// "/../"\n
// @lcpr case=end

// @lcpr case=start
// "/home//foo/"\n
// @lcpr case=end

 */
