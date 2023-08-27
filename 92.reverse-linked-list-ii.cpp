/*
 * @lc app=leetcode id=92 lang=cpp
 * @lcpr version=21913
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        for (int i = 1; i < left; ++i) {
            prev = curr;
            curr = curr->next;
        }
        ListNode* new_head = reverse(curr, right - left + 1);
        if (prev) {
            prev->next = new_head;
            return head;
        }
        return new_head;
    }

    ListNode* reverse(ListNode* head, int n) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (n) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
            n--;
        }
        head->next = curr;
        return prev;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n1\n1\n
// @lcpr case=end

 */
