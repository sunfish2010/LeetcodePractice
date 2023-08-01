/*
 * @lc app=leetcode id=841 lang=cpp
 * @lcpr version=21912
 *
 * [841] Keys and Rooms
 */

// @lc code=start
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // Use vector of bool instead of unordered_set to keep track of visited rooms.
        vector<bool> visited_rooms(rooms.size(), false);
        visited_rooms[0] = true;
        stack<int> keys;
        keys.push(0);
        while (!keys.empty()) {
            const auto next_room = keys.top();
            keys.pop();
            // visit the room.
            visited_rooms[next_room] = true;
            for (const auto& key : rooms[next_room]) {
                if (!visited_rooms[key]) {
                    keys.push(key);
                }
            }
        }
        for (const auto& visited : visited_rooms) {
            if (!visited) {
                return false;
            }
        }
        return true;
    }
};

/* Python3 version of implementation.

from typing import List


def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
    visited = [False] * len(rooms)
    visited[0] = True
    keys = [0]
    while keys:
        next_room = keys.pop()
        visited[next_room] = True
        to_visit = [key for key in rooms[next_room] if not visited[key]]
        keys.extend(to_visit)

    return all(visited)

*/
// @lc code=end

/*
// @lcpr case=start
// [[1],[2],[3],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[3,0,1],[2],[0]]\n
// @lcpr case=end

 */
