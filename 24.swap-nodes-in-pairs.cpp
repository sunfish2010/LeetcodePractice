/*
 * @lc app=leetcode id=24 lang=cpp
 * @lcpr version=21913
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        // Swap in place.
        ListNode* dummy_head = new ListNode();
        dummy_head->next = head;
        ListNode* prev = dummy_head;
        while (head && head->next) {
            ListNode* next = head->next;
            ListNode* next_head = head->next->next;
            prev->next = next;
            next->next = head;
            head->next = next_head;
            prev = head;
            head = next_head;
        }

        return dummy_head->next;
    }
};

/* Split and connect.

if (!head || !head->next) {
            return head;
        }
        ListNode* odd_head = head;
        ListNode* even_head = head->next;

        ListNode* odd_node = odd_head;
        ListNode* even_node = even_head;

        while (odd_node->next && even_node->next) {
            odd_node->next = odd_node->next->next;
            even_node->next = even_node->next->next;
            odd_node = odd_node->next;
            even_node = even_node->next;
        }
        if (odd_node->next) {
            odd_node->next = nullptr;
        }
        ListNode* dummy_head = new ListNode();
        ListNode* curr = dummy_head;
        while (even_head && odd_head) {
            ListNode* even_next = even_head->next;
            ListNode* odd_next = odd_head->next;
            curr->next = even_head;
            curr->next->next = odd_head;
            even_head = even_next;
            odd_head = odd_next;
            curr = curr->next->next;
        }
        if (odd_head) {
            curr->next = odd_head;
        }
        return dummy_head->next;
*/
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
