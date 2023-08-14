/*
 * @lc app=leetcode id=146 lang=cpp
 * @lcpr version=21913
 *
 * [146] LRU Cache
 */

// @lc code=start
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
   public:
    LRUCache(int capacity) {
        max_size = capacity;
        kv_store.clear();
        keys.clear();
    }

    int get(int key) {
        if (kv_store.count(key) == 0) {
            return -1;
        }
        bring_key_to_top(key);
        return kv_store[key];
    }

    void put(int key, int value) {
        if (kv_store.find(key) != kv_store.end()) {
            kv_store[key] = value;
            bring_key_to_top(key);
            return;
        }
        if (keys.size() == max_size) {
            int least_used_key = keys.back();
            kv_store.erase(least_used_key);
            key_index.erase(least_used_key);
            keys.pop_back();
        }
        kv_store[key] = value;
        keys.push_front(key);
        key_index[key] = keys.begin();
    }

   private:
    void bring_key_to_top(int key) {
        // Bring key to top.
        keys.erase(key_index[key]);
        keys.push_front(key);
        key_index[key] = keys.begin();
    }
    unordered_map<int, int> kv_store;
    // List is used over deque because deque will shift memory address when item is added to front or back.
    list<int> keys;
    // Iterator map can only store .begin() as .end() does not store valid memory content, while deque doesn't support .at() function.

    unordered_map<int, list<int>::iterator> key_index;
    int max_size = 0;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
