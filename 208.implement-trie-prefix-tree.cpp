/*
 * @lc app=leetcode id=208 lang=cpp
 * @lcpr version=21913
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Trie {
   public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for (const auto& c : word) {
            if (!curr->next[c - 'a']) {
                curr->next[c - 'a'] = new TrieNode();
            }
            curr = curr->next[c - 'a'];
        }
        curr->is_end = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (const auto& c : word) {
            if (!curr->next[c - 'a']) {
                return false;
            }
            curr = curr->next[c - 'a'];
        }
        return curr->is_end;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (const auto& c : prefix) {
            if (!curr->next[c - 'a']) {
                return false;
            }
            curr = curr->next[c - 'a'];
        }
        return true;
    }

   private:
    struct TrieNode {
        vector<TrieNode*> next = vector<TrieNode*>(26);
        bool is_end = false;
    };

    TrieNode* root = nullptr;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
