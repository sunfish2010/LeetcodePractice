/*
 * @lc app=leetcode id=328 lang=cpp
 * @lcpr version=21912
 *
 * [328] Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return head;
        }
        ListNode* odd_node = head;
        ListNode* even_head = head->next;
        ListNode* even_node = even_head;
        while (odd_node && even_node && odd_node->next && even_node->next) {
            odd_node->next = odd_node->next->next;
            even_node->next = even_node->next->next;
            odd_node = odd_node->next;
            even_node = even_node->next;
        }
        odd_node->next = even_head;
        return head;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3,5,6,4,7]\n
// @lcpr case=end

 */
