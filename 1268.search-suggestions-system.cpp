/*
 * @lc app=leetcode id=1268 lang=cpp
 * @lcpr version=21913
 *
 * [1268] Search Suggestions System
 */

// @lc code=start
#include <array>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Trie {
   public:
    Trie() {
        root = make_shared<Node>();
    }

    void insert(const string& s) {
        auto node = root;
        for (const auto& c : s) {
            int index = c - 'a';
            if (!node->next_word[index]) {
                node->next_word[index] = make_shared<Node>();
            }
            node = node->next_word[index];
        }
        node->is_end = true;
    }

    vector<string> words_with_prefix(string& prefix) {
        auto node = root;
        vector<string> results;
        for (const auto& c : prefix) {
            int index = c - 'a';
            if (!node->next_word[index]) {
                return results;
            }
            node = node->next_word[index];
        }
        string word = prefix;
        dfs(node, word, results);
        return results;
    }

   private:
    const static int NUM_CHAR = 26;

    struct Node {
        bool is_end = false;
        array<shared_ptr<Node>, NUM_CHAR> next_word;
    };

    void dfs(const shared_ptr<Node> curr, string& word, vector<string>& words) {
        if (words.size() == 3) {
            return;
        }
        if (curr->is_end) {
            words.push_back(word);
        }
        for (size_t i = 0; i < NUM_CHAR; ++i) {
            if (curr->next_word[i]) {
                word += 'a' + i;
                dfs(curr->next_word[i], word, words);
                word.pop_back();
            }
        }
    }
    shared_ptr<Node> root;
};

class Solution {
   public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> suggestions;
        Trie trie;
        vector<vector<string>> results;
        for (const auto& product : products) {
            trie.insert(product);
        }
        string prefix;
        for (const auto& c : searchWord) {
            prefix += c;
            results.push_back(trie.words_with_prefix(prefix));
        }
        return results;
    }
};

// @lc code=end

/*
// @lcpr case=start
// ["mobile","mouse","moneypot","monitor","mousepad"]\n"mouse"\n
// @lcpr case=end

// @lcpr case=start
// ["havana"]\n"havana"\n
// @lcpr case=end

 */
