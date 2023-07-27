/*
 * @lc app=leetcode id=2336 lang=cpp
 * @lcpr version=21912
 *
 * [2336] Smallest Number in Infinite Set
 */

// @lc code=start
#include <set>
using namespace std;

class SmallestInfiniteSet {
    SmallestInfiniteSet() {
    }

    int popSmallest() {
        removed_numbers.insert(smallest);
        int return_val = smallest;
        smallest++;
        while (removed_numbers.find(smallest) != removed_numbers.end()) {
            smallest++;
        }
        return return_val;
    }

    void addBack(int num) {
        const auto iter = removed_numbers.find(num);
        if (iter != removed_numbers.end()) {
            removed_numbers.erase(iter);
        }
        if (num < smallest) {
            smallest = num;
        }
    }

   private:
    set<int> removed_numbers;
    int smallest = 1;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end
