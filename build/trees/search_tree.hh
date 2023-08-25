/*
WIP

Base class for various search tree algorithms
*/
#include <memory>
#include <optional>

template <typename Key, typename Value>
class SearchTree {
 public:
  SearchTree();

  virtual bool empty() const = 0;

  virtual size_t size() const = 0;

  virtual bool contains(Key key) const = 0;

  virtual void erase(const Key& key) = 0;

  virtual Value& operator[] (const Key& key) = 0;
};