/*
 * @lc app=leetcode id=19 lang=cpp
 * @lcpr version=21909
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast_ptr = head;
        for (int i = 0; i < n; ++i) {
            fast_ptr = fast_ptr->next;
        }
        // fast and slow ptr are now n nodes away.
        ListNode* slow_ptr = head;
        while (fast_ptr->next) {
            fast_ptr = fast_ptr->next;
            slow_ptr = slow_ptr->next;
        }
        slow_ptr->next = slow_ptr->next->next;

        return head;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */
