/*
 * @lc app=leetcode id=2095 lang=cpp
 * @lcpr version=21909
 *
 * [2095] Delete the Middle Node of a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.

 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) {
            return nullptr;
        }
        // Since we want to delete the middle node, not finding it,
        // we need to dial back the slow ptr which is effectively forwarding the fast ptr by one iteration.
        ListNode* fast_ptr = head->next->next;
        ListNode* slow_ptr = head;
        while (fast_ptr && fast_ptr->next) {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        slow_ptr->next = slow_ptr->next->next;
        return head;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,4,7,1,2,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n
// @lcpr case=end

 */
