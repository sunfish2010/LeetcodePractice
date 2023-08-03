/*
 * @lc app=leetcode id=21 lang=cpp
 * @lcpr version=21912
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy_head = new ListNode();
        ListNode* curr_node = dummy_head;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr_node->next = list1;
                list1 = list1->next;
            } else {
                curr_node->next = list2;
                list2 = list2->next;
            }
            curr_node = curr_node->next;
        }
        curr_node->next = list1 ? list1 : list2;
        return dummy_head->next;
    }
};

/*
Python implementation
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy_head = ListNode()
        curr_node = dummy_head
        while list1 and list2:
            if list1.val < list2.val:
                curr_node.next = list1
                list1 = list1.next
            else:
                curr_node.next = list2
                list2 = list2.next
            curr_node = curr_node.next
        curr_node.next = list1 if list1 else list2
        return dummy_head.next

*/
// @lc code=end

/*
// @lcpr case=start
// [1,2,4]\n[1,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n[]\n
// @lcpr case=end

// @lcpr case=start
// []\n[0]\n
// @lcpr case=end

 */
