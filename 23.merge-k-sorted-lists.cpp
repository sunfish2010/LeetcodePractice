#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        int step = 1;
        int n = lists.size();
        while (step < n) {
            for (int i = 0; i + step < n; i += step * 2) {
                lists[i] = merge_lists(lists[i], lists[i + step]);
            }
            step *= 2;
        }
        return lists[0];
    }

   private:
    ListNode* merge_lists(ListNode* a, ListNode* b) {
        ListNode* dummy_head = new ListNode(0);
        ListNode* prev = dummy_head;
        while (a && b) {
            if (a->val < b->val) {
                prev->next = a;
                a = a->next;
            } else {
                prev->next = b;
                b = b->next;
            }
            prev = prev->next;
        }
        if (a) {
            prev->next = a;
        } else if (b) {
            prev->next = b;
        }
        return dummy_head->next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,4,5],[1,3,4],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

 */
