/*
 * @lc app=leetcode id=148 lang=cpp
 * @lcpr version=21909
 *
 * [148] Sort List
 */

// @lc code=left_start
/**
 * Definition for singly-linked list.
 *
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        int num_nodes = get_num_nodes(head);
        dummy_head->next = head;
        for (int sz = 1; sz < num_nodes; sz = sz * 2) {
            ListNode* left_start = dummy_head->next;
            // left_end points to the end of the first list.
            ListNode* left_end = left_start;
            ListNode* right_end = left_start->next;
            // Iterate between sublists.
            prev_tail = dummy_head;
            while (true) {
                // Find the right_end, left_end, left_start for current sublist;
                for (int i = 0; i < (sz - 1) && right_end && left_end; ++i) {
                    if (right_end->next) {
                        right_end = right_end->next->next ? right_end->next->next : right_end->next;
                    }
                    left_end = left_end->next;
                }
                ListNode* next_list_head = nullptr;
                if (right_end) {
                    // Save the head of next sublist, and the head of current right list.
                    next_list_head = right_end->next;
                    // Split the list.
                    right_end->next = nullptr;
                }
                ListNode* right_start = nullptr;
                if (left_end) {
                    right_start = left_end->next;
                    left_end->next = nullptr;
                }
                merge(left_start, left_end, right_start, right_end);
                if (!next_list_head) {
                    break;
                }
                // Reset left_start, left_end, right_end
                left_start = next_list_head;
                left_end = left_start;
                right_end = left_start->next;
            }
        }
        return dummy_head->next;
    }

    int get_num_nodes(ListNode* head) {
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
    }

    void merge(ListNode* left_start, ListNode* left_end, ListNode* right_start, ListNode* right_end) {
        if (left_end && right_start && left_end->val < right_start->val) {
            // already sorted.
            left_end->next = right_start;
            prev_tail->next = left_start;
            prev_tail = right_end;
            return;
        } else {
            ListNode* tmp_head = new ListNode(0);
            ListNode* curr = tmp_head;
            while (left_start && right_start) {
                if (left_start->val <= right_start->val) {
                    curr->next = left_start;
                    left_start = left_start->next;
                } else {
                    curr->next = right_start;
                    right_start = right_start->next;
                }
                curr = curr->next;
            }
            curr->next = left_start ? left_start : right_start;
            // Link new list to the previous tail.
            prev_tail->next = tmp_head->next;
            prev_tail = left_start ? left_end : right_end;
        }
    }

   private:
    ListNode* prev_tail = new ListNode(0);
    ListNode* dummy_head = new ListNode(0);
};
// @lc code=end

/*
// @lcpr case=left_start
// [4,2,1,3]\n
// @lcpr case=end

// @lcpr case=left_start
// [-1,5,3,4,0]\n
// @lcpr case=end

// @lcpr case=left_start
// []\n
// @lcpr case=end

 */
