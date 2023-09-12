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
        if (!head) {
            return nullptr;
        }
        if (!(head->next)) {
            return head;
        }
        ListNode* curr = head;
        ListNode* dummy_head = new ListNode(0);
        ListNode* prev = dummy_head;
        while (curr && curr->next) {
            prev->next = curr->next;
            ListNode* next_node = curr->next->next;
            curr->next->next = curr;
            curr->next = next_node;
            prev = curr;
            curr = next_node;
        }
        return dummy_head->next;
    }
};
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
