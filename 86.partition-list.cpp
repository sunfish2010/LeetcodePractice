/*
 * @lc app=leetcode id=86 lang=cpp
 * @lcpr version=21913
 *
 * [86] Partition List
 */

// @lc code=start
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy_left = new ListNode(0);
        ListNode* dummy_right = new ListNode(0);
        ListNode* small_prev = dummy_left;
        ListNode* large_prev = dummy_right;
        ListNode* curr = head;
        while (curr) {
            if (curr->val < x) {
                small_prev->next = curr;
                small_prev = curr;
            } else {
                large_prev->next = curr;
                large_prev = curr;
            }
            curr = curr->next;
        }
        if (large_prev) {
            large_prev->next = nullptr;
        }
        small_prev->next = dummy_right->next;
        return dummy_left->next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,4,3,2,5,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n2\n
// @lcpr case=end

 */
