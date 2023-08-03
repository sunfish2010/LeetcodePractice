/*
 * @lc app=leetcode id=2130 lang=cpp
 * @lcpr version=21912
 *
 * [2130] Maximum Twin Sum of a Linked List
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
    int pairSum(ListNode* head) {
        if (!head->next->next) {
            return head->val + head->next->val;
        }
        ListNode* fast = head->next->next;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* end = inverse_linked_list(slow->next);
        int max_sum = 0;
        while (end) {
            max_sum = max(max_sum, end->val + head->val);
            head = head->next;
            end = end->next;
        }
        return max_sum;
    }

   private:
    ListNode* inverse_linked_list(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [5,4,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,100000]\n
// @lcpr case=end

 */
