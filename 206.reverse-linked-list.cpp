/*
 * @lc app=leetcode id=206 lang=cpp
 * @lcpr version=21912
 *
 * [206] Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            // Store original next node;
            ListNode* next = curr->next;
            // Reverse the node;
            curr->next = prev;
            // Iterate the next node.
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

/*

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        curr = head
        while curr:
            next = curr.next
            curr.next= prev
            prev = curr
            curr = next
        return prev
*/
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
