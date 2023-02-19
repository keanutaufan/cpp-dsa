#ifndef CPPDSA_DATA_STRUCTURE_AVL_TREE_IPP_
#define CPPDSA_DATA_STRUCTURE_AVL_TREE_IPP_

#include <cstddef>
#include <stdexcept>
#include <string>
#include <sstream>
#include <utility>
#include "AVLTree.hpp"

namespace DSA {
    template <typename Key, typename Value>
    int AVLTree<Key, Value>::_default_compare(const Key& key1, const Key& key2) {
        if (key1 > key2) {
            return 1;
        }
        else if (key1 < key2) {
            return -1;
        }
        else {
            return 0;
        }
    }

    template <typename Key, typename Value>
    AVLTree<Key, Value>::AVLNode<Key, Value>* AVLTree<Key, Value>::_create_node(const Key& key, const Value& value) {
        AVLNode<Key, Value>* newNode = new AVLNode<Key, Value>();
        newNode->key = key;
        newNode->data = value;
        newNode->height = 0;
        return newNode;
    }

    template <typename Key, typename Value>
    int AVLTree<Key, Value>::_height(AVLNode<Key, Value>* node) const {
        if (node == nullptr) {
            return -1;
        }

        return node->height;
    }

    template <typename Key, typename Value>
    int AVLTree<Key, Value>::_balance_factor(AVLNode<Key, Value>* node) const {
        return _height(node->left) - _height(node->right);
    }

    template <typename Key, typename Value>
    void AVLTree<Key, Value>::_update_height(AVLNode<Key, Value>* node) {
        node->height = std::max(_height(node->left), _height(node->right)) + 1;
    }

    template <typename Key, typename Value>
    AVLTree<Key, Value>::AVLNode<Key, Value>* AVLTree<Key, Value>::_left_rotate(AVLNode<Key, Value>* root) {
        AVLNode<Key, Value>* newRoot = root->right;
        AVLNode<Key, Value>* newRootLeft = newRoot->left;
        
        newRoot->left = root;
        root->right = newRootLeft;

        _update_height(root);
        _update_height(newRoot);

        return newRoot;
    }

    template <typename Key, typename Value>
    AVLTree<Key, Value>::AVLNode<Key, Value>* AVLTree<Key, Value>::_right_rotate(AVLNode<Key, Value>* root) {
        AVLNode<Key, Value>* newRoot = root->left;
        AVLNode<Key, Value>* newRootRight = newRoot->right;

        newRoot->right = root;
        root->left = newRootRight;

        _update_height(root);
        _update_height(newRoot);

        return newRoot;
    }

    template <typename Key, typename Value>
    AVLTree<Key, Value>::AVLNode<Key, Value>* AVLTree<Key, Value>::_insert(AVLNode<Key, Value>* root, AVLNode<Key, Value>* newNode) {
        if (root == nullptr) {
            return newNode;
        }
        else if (_compare(newNode->key, root->key) < 0) {
            root->left = _insert(root->left, newNode);
        }
        else if (_compare(newNode->key, root->key) > 0) {
            root->right = _insert(root->right, newNode);
        }
        else {
            throw std::runtime_error("Key already exist.");
        }

        _update_height(root);
        const int bf = _balance_factor(root);

        if (bf > 1) {
            // Left-Left imbalance
            if (_compare(newNode->key, root->left->key) < 0) {
                return _right_rotate(root);
            }
            // Left-Right imbalance
            else {
                root->left = _left_rotate(root->left);
                return _right_rotate(root);
            }
        }
        else if (bf < -1) {
            // Right-Right imbalance
            if (_compare(newNode->key, root->right->key) > 0) {
                return _left_rotate(root);
            }
            // Right-Left imbalance            
            else {
                root->right = _right_rotate(root->right);
                return _left_rotate(root);
            }
        }
        
        return root;
    }

    template <typename Key, typename Value>
    AVLTree<Key, Value>::AVLNode<Key, Value>* AVLTree<Key, Value>::_remove(AVLNode<Key, Value>* root, const Key& key) {
        if (root == nullptr) {
            throw std::out_of_range("Key does not exist.");
        }
        else if (_compare(key, root->key) < 0) {
            root->left = _remove(root->left, key);
        }
        else if (_compare(key, root->key) > 0) {
            root->right = _remove(root->right, key);
        }
        else {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            else if (root->left == nullptr) {
                AVLNode<Key, Value>* newChild = root->right;
                delete root;
                return newChild;
            }
            else if (root->right == nullptr) {
                AVLNode<Key, Value>* newChild = root->left;
                delete root;
                return newChild;
            }
            else {
                AVLNode<Key, Value>* successor = root->right;
                while (successor->left != nullptr) {
                    successor = successor->left;
                }

                root->data = std::move(successor->data);
                root->key = successor->key;
                root->right = _remove(root->right, successor->key);
            }
        }

        _update_height(root);
        const int bf = _balance_factor(root);
        
        if (bf > 1) {
            // Left-Left imbalance
            if (_balance_factor(root->left) >= 0) {
                return _right_rotate(root);
            }
            // Left-Right imbalance
            else {
                root->left = _left_rotate(root->left);
                return _right_rotate(root);
            }
        }
        else if (bf < -1) {
            // Right-Right imbalance
            if (_balance_factor(root->right) <= 0) {
                return _left_rotate(root);
            }
            // Right-Left imbalance
            else {
                root->right = _right_rotate(root->right);
                return _left_rotate(root);
            }
        }

        return root; 
    }

    template <typename Key, typename Value>
    void AVLTree<Key, Value>::_clear(AVLNode<Key, Value>* root) {
        if (root != nullptr) {
            _clear(root->left);
            _clear(root->right);
            delete root;
        }
    }

    template <typename Key, typename Value>
    void AVLTree<Key, Value>::_preorder(AVLNode<Key, Value>* root, std::ostringstream& outstring) const {
        if (root != nullptr) {
            outstring << "{" << root->key << ":" << " " << root->data << "} ";
            _preorder(root->left, outstring);
            _preorder(root->right, outstring);
        }
    }

    template <typename Key, typename Value>
    void AVLTree<Key, Value>::_inorder(AVLNode<Key, Value>* root, std::ostringstream& outstring) const {
        if (root != nullptr) {
            _inorder(root->left, outstring);
            outstring << "{" << root->key << ":" << " " << root->data << "} ";
            _inorder(root->right, outstring);
        }
    }

    template <typename Key, typename Value>
    void AVLTree<Key, Value>::_postorder(AVLNode<Key, Value>* root, std::ostringstream& outstring) const {
        if (root != nullptr) {
            _postorder(root->left, outstring);
            _postorder(root->right, outstring);
            outstring << "{" << root->key << ":" << " " << root->data << "} ";
        }
    }

    template <typename Key, typename Value>
    AVLTree<Key, Value>::AVLTree(int (*comparator)(const Key& key1, const Key& key2)) {
        m_root = nullptr;
        m_size = 0;
        _compare = comparator;
    }

    template <typename Key, typename Value>
    void AVLTree<Key, Value>::insert(const Key& key, const Value& value) {
        AVLNode<Key, Value>* newNode = _create_node(key, value);
        m_root = _insert(m_root, newNode);
        m_size++;
    }

    template <typename Key, typename Value>
    void AVLTree<Key, Value>::remove(const Key& key) {
        if (m_root == nullptr) {
            throw std::underflow_error("Tree is empty.");
        }

        m_root = _remove(m_root, key);
        m_size--;
    }

    template <typename Key, typename Value>
    bool AVLTree<Key, Value>::is_empty() const {
        return m_size == 0;
    }

    template <typename Key, typename Value>
    std::size_t AVLTree<Key, Value>::size() const {
        return m_size;
    }

    template <typename Key, typename Value>
    Value& AVLTree<Key, Value>::min() {
        return const_cast<Value&>(static_cast<const AVLTree<Key, Value>&>(*this).min());
    }

    template <typename Key, typename Value>
    const Value& AVLTree<Key, Value>::min() const {
        if (m_root == nullptr) {
            throw std::out_of_range("Tree is empty");
        }

        AVLNode<Key, Value>* cursor = m_root;
        while (cursor->left != nullptr) {
            cursor = cursor->left;
        }

        return cursor->data;
    }

    template <typename Key, typename Value>
    Value& AVLTree<Key, Value>::max() {
        return const_cast<Value&>(static_cast<const AVLTree<Key, Value>&>(*this).max());
    }

    template <typename Key, typename Value>
    const Value& AVLTree<Key, Value>::max() const {
        if (m_root == nullptr) {
            throw std::out_of_range("Tree is empty");
        }

        AVLNode<Key, Value>* cursor = m_root;
        while (cursor->right != nullptr) {
            cursor = cursor->right;
        }

        return cursor->data;
    }


    template <typename Key, typename Value>
    bool AVLTree<Key, Value>::contains(const Key& key) const {
        AVLNode<Key, Value>* cursor = m_root;
        while (cursor != nullptr) {
            if (_compare(key, cursor->key) < 0) {
                cursor = cursor->left;
            }
            else if (_compare(key, cursor->key) > 0) {
                cursor = cursor->right;
            }
            else {
                return true;
            }
        }

        return false;
    }

    template <typename Key, typename Value>
    Value& AVLTree<Key, Value>::at(const Key& key) {
        return const_cast<Value&>(static_cast<const AVLTree<Key, Value>&>(*this).at(key));
    }

    template <typename Key, typename Value>
    const Value& AVLTree<Key, Value>::at(const Key& key) const {
        AVLNode<Key, Value>* cursor = m_root;
        while (cursor != nullptr) {
            if (_compare(key, cursor->key) < 0) {
                cursor = cursor->left;
            }
            else if (_compare(key, cursor->key) > 0) {
                cursor = cursor->right;
            }
            else {
                return cursor->data;
            }
        }

        throw std::out_of_range("Key does not exist.");
    }

    template <typename Key, typename Value>
    Value& AVLTree<Key, Value>::operator[](const Key& key) {
        AVLNode<Key, Value>* cursor = m_root;
        while (cursor != nullptr) {
            if (_compare(key, cursor->key) < 0) {
                cursor = cursor->left;
            }
            else if (_compare(key, cursor->key) > 0) {
                cursor = cursor->right;
            }
            else {
                return cursor->data;
            }
        }

        insert(key, Value());
        return operator[](key);
    }

    template <typename Key, typename Value>
    std::string AVLTree<Key, Value>::preorder() const {
        std::ostringstream outstring;
        _preorder(m_root, outstring);
        return outstring.str();
    }

    template <typename Key, typename Value>
    std::string AVLTree<Key, Value>::inorder() const {
        std::ostringstream outstring;
        _inorder(m_root, outstring);
        return outstring.str();
    }

    template <typename Key, typename Value>
    std::string AVLTree<Key, Value>::postorder() const {
        std::ostringstream outstring;
        _postorder(m_root, outstring);
        return outstring.str();
    }

    template <typename Key, typename Value>
    AVLTree<Key, Value>::~AVLTree() {
        _clear(m_root);
        m_size = 0;
    }
}

#endif // CPPDSA_DATA_STRUCTURE_AVL_TREE_IPP_