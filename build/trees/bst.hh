#include "trees/search_tree.hh"

template <typename Key, typename Value>
class BinarySearchTree final : SearchTree<Key, Value> {
 public:
  bool empty() { return size() == 0; }

  size_t size() const { return size(root_); }

  bool contains(const Key& key) const { return get(root_, key)!=nullptr; }

  Value& operator[] (const Key& key) { 
    return get(root_, key); 
    }

//   void insert(const Key& key, const Value& val) {
//     root_ = insert(root_, key, val);
//   }

  void erase(const Key& key) { root_ = erase(root_, key); }

 protected:
  struct Node {
    Key key;
    Value value;
    size_t size;
    Node(const Key& k, const Value& v, size_t s) : key(k), value(v), size(s) {}
    std::shared_ptr<Node> left, right;
  };

 private:
  std::unique_ptr<Node> root_;

  size_t size(const std::shared_ptr<Node> node) const {
    if (!node) {
      return 0;
    }
    return node->size;
  }

  std::shared_ptr<Node> get(const std::shared_ptr<Node> node, const Key& key) const {
    if (!node) {
      return nullptr;
    }
    if (key < node->key) {
      return get(node->left, key);
    } else if (key > node->ket) {
      return get(node->right, key);
    }
    return node;
  }

//   std::shared_ptr<Node> insert(const std::shared_ptr<Node> node, const Key& key,
//                                const Value& val) {
//     if (!node) {
//       return std::make_shared<Node>(key, val, 1);
//     }

//     if (key == node->key) {
//       node->val = val;
//     } else if (key < node->key) {
//       node->left = insert(node->left, key, val);
//     } else {
//       node->right = insert(node->right, key, val);
//     }

//     node->size = 1 + size(node->left) + size(node->right);
//     return node;
//   }

  std::shared_ptr<Node> erase(const std::shared_ptr<Node> node, const Key& key) {
    if (!node) {
      return node;
    }
    if (key < node->key) {
      node->left = erase(node->left, key);
    } else if (key > node->key) {
      node->right = erase(node->right, key);
    } else {
      if (!node->left) {
        return node->right;
      }
      if (!node->right) {
        return node->left;
      }
      node->val = min(node->right);
      node->right = delete_min(node->right);
    }

    node->size = 1 + size(node->left) + size(node->right);
    return node;
  }

  Value min(const std::shared_ptr<Node> node) const { return min_node(node)->val; }

  std::shared_ptr<Node> min_node(const std::shared_ptr<Node> node) const {
    while (node->left) {
      node = node->left;
    }
    return node;
  }

  std::shared_ptr<Node> delete_min(const std::shared_ptr<Node> node) {
    if (!node->left) {
      return node->right;
    }
    node->left = delete_min(node->left);
    node->size = size(node->left) + size(node->right) + 1;
    return node;
  }
};