#ifndef CPPDSA_DATA_STRUCTURE_AVL_TREE_HPP_
#define CPPDSA_DATA_STRUCTURE_AVL_TREE_HPP_

#include <cstddef>
#include <sstream>

namespace DSA {
    template <typename Key, typename Value>
    class AVLTree {
    private:
        template <typename _Key, typename _Value>
        struct AVLNode {
            _Key key;
            _Value data;
            AVLNode<_Key, _Value>* left;
            AVLNode<_Key, _Value>* right;
            int height;
        };

        AVLNode<Key, Value>* m_root;
        std::size_t m_size;
        int (*_compare)(const Key& key1, const Key& key2);

        static int _default_compare(const Key& key1, const Key& key2);

        AVLNode<Key, Value>* _create_node(const Key& key, const Value& value);

        int _height(AVLNode<Key, Value>* node) const;
        int _balance_factor(AVLNode<Key, Value>* node) const;
        void _update_height(AVLNode<Key, Value>* node);

        AVLNode<Key, Value>* _left_rotate(AVLNode<Key, Value>* root);
        AVLNode<Key, Value>* _right_rotate(AVLNode<Key, Value>* root);

        AVLNode<Key, Value>* _insert(AVLNode<Key, Value>* root, AVLNode<Key, Value>* newNode);
        AVLNode<Key, Value>* _remove(AVLNode<Key, Value>* root, const Key& key);
        void _clear(AVLNode<Key, Value>* root);

        void _preorder(AVLNode<Key, Value>* root, std::ostringstream& outstring) const;
        void _inorder(AVLNode<Key, Value>* root, std::ostringstream& outstring) const;
        void _postorder(AVLNode<Key, Value>* root, std::ostringstream& outstring) const;
        

    public:
        AVLTree(int (*comparator)(const Key& key1, const Key& key2) = _default_compare);

        void insert(const Key& key, const Value& value);
        void remove(const Key& key);

        bool is_empty() const;
        std::size_t size() const;

        Value& min();
        const Value& min() const;
        Value& max();
        const Value& max() const;

        bool contains(const Key& key) const;
        Value& at(const Key& key);
        const Value& at(const Key& key) const;
        Value& operator[](const Key& key);

        std::string preorder() const;
        std::string inorder() const;
        std::string postorder() const;

        ~AVLTree();
    };
}

#include "AVLTree.ipp"

#endif // CPPDSA_DATA_STRUCTURE_AVL_TREE_HPP_