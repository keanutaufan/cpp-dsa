#ifndef CPPDSA_DATA_STRUCTURE_BINARY_SEARCH_TREE_HPP_
#define CPPDSA_DATA_STRUCTURE_BINARY_SEARCH_TREE_HPP_

#include <cstddef>
#include <sstream>

namespace DSA {
    template <typename T>
    class BinarySearchTree {
    private:
        template <typename U>
        struct BSTNode {
            U data;
            BSTNode<U>* left;
            BSTNode<U>* right;
        };

        BSTNode<T>* _create_node(const T& value);
        static int _default_compare(const T& value1, const T& value2);
        BSTNode<T>* _get_reference(BSTNode<T>* rootNode, const T& value);

        void _remove(const T& value, BSTNode<T>* rootNode);
        void _clear(BSTNode<T>* rootNode);
        int _height(BSTNode<T>* rootNode) const;

        BSTNode<T>* _predecessor(BSTNode<T>* rootNode, const T& value);
        BSTNode<T>* _successor(BSTNode<T>* rootNode, const T& value);

        void _preorder(BSTNode<T>* rootNode, std::ostringstream& outstring) const;
        void _inorder(BSTNode<T>* rootNode, std::ostringstream& outstring) const;
        void _postorder(BSTNode<T>* rootNode, std::ostringstream& outstring) const;

        BSTNode<T>* m_root;
        std::size_t m_size;
        int (*_compare)(const T& value1, const T& value2);

    public:
        BinarySearchTree(int (*compare)(const T&, const T&) = _default_compare);
        
        void insert(const T& value);
        void remove(const T& value);

        bool contains(const T& value) const;
        const T& search(const T& value);

        const T& min() const;
        const T& max() const;

        const T& predecessor(const T& value);
        const T& successor(const T& value);

        std::size_t size() const;
        bool is_empty() const;
        int height() const;
        
        std::string preorder() const;
        std::string inorder() const;
        std::string postorder() const;

        ~BinarySearchTree();
    };
}

#include "BinarySearchTree.ipp"

#endif // CPPDSA_DATA_STRUCTURE_BINARY_SEARCH_TREE_HPP_