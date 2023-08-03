/*
 * @lc app=leetcode id=141 lang=cpp
 * @lcpr version=21912
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.

 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    bool hasCycle(ListNode* head) {
        if (!head) {
            return false;
        }
        ListNode* fast_ptr = head->next;
        ListNode* slow_ptr = head;
        while (fast_ptr != slow_ptr) {
            if (!fast_ptr || !fast_ptr->next) {
                return false;
            }
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,0,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1]\n-1\n
// @lcpr case=end

 */
