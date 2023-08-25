/*
TODO: Add iterator for container.
TODO: Remove magic numbers.
Needs more testing.

This is my own attemptation to implement unordered_map using separate chaining.
The implementation can be modified for unordered_set as well.
*/
#ifndef SC_HASH_TABLE
#define SC_HASH_TABLE

#include <functional>
#include <memory>
#include <vector>

#include "hashtable/hash_table.hh"

template <typename Key, typename Value>
class SeparateChainingHashTable final : public HashTable<Key, Value> {
 public:
  SeparateChainingHashTable() { table_.resize(capacity_); }

  SeparateChainingHashTable(size_t size) {
    capacity_ = size;
    table_ = std::vector<HashEntry>(size);
  }

  Value& operator[](const Key& key) {
    auto entry = find(key);
    if (entry) {
      return entry->val;
    }
    // Variable not initialized, not sure how this is handled in STL.
    Value val;
    return insert(key, val)->val;
  }

  bool contains(const Key& key) const { return find(key) != nullptr; }

  void erase(const Key& key) {
    if (!contains(key)) {
      return;
    }
    delete_key(key);
  }
  // Not sure how iterator for unordered_map is implemented, from https://en.cppreference.com/w/cpp/iterator/iterator_tags 
  // there are clearly many iterator types

 protected:
  struct HashEntry {
    Key key;
    Value val;
    std::shared_ptr<HashEntry> next;

    HashEntry(const Key k, const Value v) : key(k), val(v) {}
  };

  size_t hash(const Key& key) const {
    size_t h = std::hash<Key>{}(key);
    h ^= (h >> 20) ^ (h >> 12) ^ (h >> 7) ^ (h >> 4);
    return h % (capacity_ - 1);
  }

  const static size_t INIT_CAPACITY = 10;
  std::vector<std::shared_ptr<HashEntry>> table_;
  int capacity_ = INIT_CAPACITY;

 private:
  using HashTable<Key, Value>::num_elements_;

  std::shared_ptr<HashEntry> insert(const Key& key, const Value& val) {
    // We want on average 5 items per table entry. Resize when half full.
    if (num_elements_ >= 10 * capacity_) {
      resize(2 * capacity_);
    }
    size_t hash_index = hash(key);
    std::shared_ptr<HashEntry> inserted;
    if (!table_[hash_index]) {
      table_[hash_index] = std::make_shared<HashEntry>(key, val);
      inserted = table_[hash_index];
    } else {
      auto curr = table_[hash_index];
      while (curr->next) {
        curr = curr->next;
      }
      curr->next = std::make_shared<HashEntry>(key, val);
      inserted = curr->next;
    }
    num_elements_++;
    return inserted;
  }

  void delete_key(const Key& key) {
    size_t hash_index = hash(key);
    if (table_[hash_index]) {
      table_[hash_index] = nullptr;
    } else {
      auto curr = table_[hash_index];
      if (curr->key == key) {
        table_[hash_index] = curr->next;
      }
      while (curr->next) {
        if (curr->next->key == key) {
          curr->next = curr->next->next;
          break;
        }
        curr = curr->next;
      }
    }
    // Resize when a quarter full.
    num_elements_--;
    if (capacity_ > INIT_CAPACITY && num_elements_ <= 2 * capacity_) {
      resize(capacity_ / 2);
    }
  }

  std::shared_ptr<HashEntry> find(const Key& key) const {
    size_t hash_index = hash(key);
    if (!table_[hash_index]) {
      return nullptr;
    }
    auto curr = table_[hash_index];
    while (curr) {
      if (curr->key == key) {
        return curr;
      }
      curr = curr->next;
    }
    return nullptr;
  }

  void resize(size_t new_size) {
    SeparateChainingHashTable<Key, Value> tmp;
    for (const auto& entry : table_) {
      auto curr = entry;
      while (curr) {
        tmp.insert(curr->key, curr->val);
        curr = curr->next;
      }
    }
    *this = std::move(tmp);
  }
};

#endif
