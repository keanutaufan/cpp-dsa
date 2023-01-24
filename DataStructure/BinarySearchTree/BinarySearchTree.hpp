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

        BSTNode<T>* _createNode(const T& value);
        static int _defaultCompare(const T& value1, const T& value2);
        BSTNode<T>* _getReference(BSTNode<T>* rootNode, const T& value);

        void _remove(const T& value, BSTNode<T>* rootNode);
        void _clear(BSTNode<T>* rootNode);
        int _height(BSTNode<T>* rootNode);

        BSTNode<T>* _predecessor(BSTNode<T>* rootNode, const T& value);
        BSTNode<T>* _successor(BSTNode<T>* rootNode, const T& value);

        void _preorder(BSTNode<T>* rootNode, std::ostringstream& outstring);
        void _inorder(BSTNode<T>* rootNode, std::ostringstream& outstring);
        void _postorder(BSTNode<T>* rootNode, std::ostringstream& outstring);

        BSTNode<T>* root;
        std::size_t BSTSize;
        int (*_compare)(const T& value1, const T& value2);

    public:
        BinarySearchTree(int (*compare)(const T&, const T&) = _defaultCompare);
        
        void insert(const T& value);
        void remove(const T& value);

        bool contains(const T& value);
        const T& search(const T& value);

        const T& min();
        const T& max();

        const T& predecessor(const T& value);
        const T& successor(const T& value);

        std::size_t size();
        bool isEmpty();
        int height();
        
        std::string preorder();
        std::string inorder();
        std::string postorder();

        ~BinarySearchTree();
    };
}

#include "BinarySearchTree.ipp"

#endif // CPPDSA_DATA_STRUCTURE_BINARY_SEARCH_TREE_HPP_