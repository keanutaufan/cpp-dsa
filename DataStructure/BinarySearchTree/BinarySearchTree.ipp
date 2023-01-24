#ifndef CPPDSA_DATA_STRUCTURE_BINARY_SEARCH_TREE_IPP_
#define CPPDSA_DATA_STRUCTURE_BINARY_SEARCH_TREE_IPP_

#include <cstddef>
#include <stdexcept>
#include <sstream>
#include "BinarySearchTree.hpp"

namespace DSA {
    template <typename T>
    BinarySearchTree<T>::BSTNode<T>* BinarySearchTree<T>::_createNode(const T& value) {
        BSTNode<T>* newNode = new BSTNode<T>();
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    template <typename T>
    int BinarySearchTree<T>::_defaultCompare(const T& value1, const T& value2) {
        if (value1 < value2) {
            return -1;
        }
        else if (value1 > value2) {
            return 1;
        }
        else {
            return 0;
        }
    }

    template <typename T>
    BinarySearchTree<T>::BSTNode<T>* BinarySearchTree<T>::_getReference(BSTNode<T>* rootNode, const T& value) {
        if (rootNode == nullptr) {
            throw std::runtime_error("Element not found.");
        }

        BSTNode<T>* cursor = rootNode;
        while (cursor != nullptr) {
            if (_compare(value, cursor->data) < 0) {
                cursor = cursor->left;
            }
            else if (_compare(value, cursor->data) > 0) {
                cursor = cursor->right;
            }
            else {
                return cursor;
            }
        }

        throw std::runtime_error("Element not found.");
    }

    template <typename T>
    void BinarySearchTree<T>::_remove(const T& value, BSTNode<T>* rootNode) {
        BSTNode<T>* targetNode = rootNode;
        BSTNode<T>* targetParent = rootNode;
        bool found = false;

        while (targetNode != nullptr) {
            if (_compare(value, targetNode->data) == 0) {
                found = true;
                break;
            }
            
            targetParent = targetNode;
            if (_compare(value, targetNode->data) < 0) {
                targetNode = targetNode->left;
            }
            else if (_compare(value, targetNode->data) > 0) {
                targetNode = targetNode->right;
            }
        }

        if (!found) {
            throw std::runtime_error("Element not found.");
        }

        // When the node to delete is a leaf node, break the link from the parent to the node
        // and release alocated memory for the node.
        if (targetNode->left == nullptr && targetNode->right == nullptr) {
            if (targetParent->left == targetNode) {
                targetParent->left = nullptr;
            }
            else if (targetParent->right == targetNode) {
                targetParent->right = nullptr;
            }
            else {
                throw std::runtime_error("Uncaught exception when removing link to deleted member of BST.");
            }
            delete targetNode;
        }

        // When the node to delete only has right child, update the link from the parent to the
        // right link of the deleted node and release alocated memory for the node.
        else if (targetNode->left == nullptr) {
            if (targetParent->left == targetNode) {
                targetParent->left = targetNode->right;
            }
            else if (targetParent->right == targetNode) {
                targetParent->right = targetNode->right;
            }
            else {
                throw std::runtime_error("Uncaught exception when updating link to deleted member of BST.");
            }
            delete targetNode;
        }

        // When the node to delete only has left child, update the link from the parent to the
        // left link of the deleted node and release alocated memory for the node.
        else if (targetNode->right == nullptr) {
            if (targetParent->left == targetNode) {
                targetParent->left = targetNode->left;
            }
            else if (targetParent->right == targetNode) {
                targetParent->right = targetNode->left;
            }
            else {
                throw std::runtime_error("Uncaught exception when updating link to deleted member of BST.");
            }
            delete targetNode;
        }

        // When the node to delete has both left and right child, update the value of the node to the
        // maximum value from the node's left subtree (i.e. predecessor node) and remove the duplicate node.
        else {
            // Maximum value from a tree is in the rightmost node from the root.
            BSTNode<T>* predecessorNode = targetNode->left;
            while (predecessorNode->right != nullptr) {
                predecessorNode = predecessorNode->right;
            }
            
            T newDeletedValue = predecessorNode->data;
            this->_remove(predecessorNode->data, targetNode);
            targetNode->data = newDeletedValue;
        }
    }

    template <typename T>
    void BinarySearchTree<T>::_clear(BSTNode<T>* rootNode) {
        if (rootNode != nullptr) {
            this->_clear(rootNode->left);
            this->_clear(rootNode->right);
            delete rootNode;
        }
    }

    template <typename T>
    int BinarySearchTree<T>::_height(BSTNode<T>* rootNode) {
        if (rootNode == nullptr) {
            return -1;
        }
        else {
            int leftHeight = this->_height(rootNode->left);
            int rightHeight = this->_height(rootNode->right);
            return std::max(leftHeight, rightHeight) + 1;
        }
    }

    template <typename T>
    BinarySearchTree<T>::BSTNode<T>* BinarySearchTree<T>::_predecessor(BSTNode<T>* rootNode, const T& value) {
        BSTNode<T>* currentNode = this->_getReference(rootNode, value);
        BSTNode<T>* predecessor = nullptr;

        if (currentNode->left != nullptr) {
            predecessor = currentNode->left;
            while (predecessor->right != nullptr) {
                predecessor = predecessor->right;
            }
            return predecessor;
        }
        else {
            BSTNode<T>* cursor = this->root;
            while (cursor != currentNode) {
                if (_compare(currentNode->data, cursor->data) < 0) {
                    cursor = cursor->left;
                }
                else if (_compare(currentNode->data, cursor->data) > 0) {
                    predecessor = cursor;
                    cursor = cursor->right;
                }
                else {
                    break;
                }
            }

            if (predecessor == nullptr) {
                throw std::out_of_range("Predecessor does not exist.");
            }
            else {
                return predecessor;
            }
        }
    }

    template <typename T>
    BinarySearchTree<T>::BSTNode<T>* BinarySearchTree<T>::_successor(BSTNode<T>* rootNode, const T& value) {
        BSTNode<T>* currentNode = this->_getReference(rootNode, value);
        BSTNode<T>* successor = nullptr;

        if (currentNode->right != nullptr) {
            successor = currentNode->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }
            return successor;
        }
        else {
            BSTNode<T>* cursor = this->root;
            while (cursor != currentNode) {
                if (_compare(currentNode->data, cursor->data) < 0) {
                    successor = cursor;
                    cursor = cursor->left;
                }
                else if (_compare(currentNode->data, cursor->data) > 0) {
                    cursor = cursor->right;
                }
                else {
                    break;
                }
            }

            if (successor == nullptr) {             
                throw std::out_of_range("Successor does not exist.");
            }
            else {
                return successor;
            }
        }
    }

    template <typename T>
    void BinarySearchTree<T>::_preorder(BSTNode<T>* rootNode, std::ostringstream& outstring) {
        if (rootNode != nullptr) {
            outstring << rootNode->data << " ";
            this->_preorder(rootNode->left, outstring);
            this->_preorder(rootNode->right, outstring);
        }
    }

    template <typename T>
    void BinarySearchTree<T>::_inorder(BSTNode<T>* rootNode, std::ostringstream& outstring) {
        if (rootNode != nullptr) {
            this->_inorder(rootNode->left, outstring);
            outstring << rootNode->data << " ";
            this->_inorder(rootNode->right, outstring);
        }
    }

    template <typename T>
    void BinarySearchTree<T>::_postorder(BSTNode<T>* rootNode, std::ostringstream& outstring) {
        if (rootNode != nullptr) {
            this->_postorder(rootNode->left, outstring);
            this->_postorder(rootNode->right, outstring);
            outstring << rootNode->data << " ";
        }
    }

    template <typename T>
    BinarySearchTree<T>::BinarySearchTree(int (*compare)(const T&, const T&)) {
        this->root = nullptr;
        this->_compare = compare;
        this->BSTSize = 0;
    }

    template <typename T>
    void BinarySearchTree<T>::insert(const T& value) {
        BSTNode<T> *newNode = this->_createNode(value);

        if (this->root == nullptr) {
            this->root = newNode;
        }
        else {
            BSTNode<T>* cursor = this->root;
            BSTNode<T>* insertPos = this->root;
            while (cursor != nullptr) {
                insertPos = cursor;
                if (_compare(value, cursor->data) <= 0) {
                    cursor = cursor->left;
                }
                else {
                    cursor = cursor->right;
                }
            }
            if (_compare(value, insertPos->data) <= 0) {
                insertPos->left = newNode;
            }
            else {
                insertPos->right = newNode;
            }
        }
        
        this->BSTSize++;
    }

    template <typename T>
    void BinarySearchTree<T>::remove(const T& value) {
        if (this->root == nullptr) {
            throw std::underflow_error("Tree is empty.");
        }
        
        this->_remove(value, this->root);
        this->BSTSize--;
    }

    template <typename T>
    bool BinarySearchTree<T>::contains(const T& value) {
        if (this->root == nullptr) {
            return false;
        }
        
        BSTNode<T>* cursor = this->root;
        while (cursor != nullptr) {
            if (_compare(value, cursor->data) < 0) {
                cursor = cursor->left;
            }
            else if (_compare(value, cursor->data) > 0) {
                cursor = cursor->right;
            }
            else {
                return true;
            }
        }
        return false;
    }

    template <typename T>
    const T& BinarySearchTree<T>::search(const T& value) {
        return this->_getReference(this->root, value)->data;
    }

    template <typename T>
    const T& BinarySearchTree<T>::min() {
        if (this->isEmpty()) {
            throw std::out_of_range("Tree is empty.");
        }

        BSTNode<T>* cursor = this->root;
        while (cursor->left != nullptr) {
            cursor = cursor->left;
        }
        return cursor->data;
    }

    template <typename T>
    const T& BinarySearchTree<T>::max() {
        if (this->isEmpty()) {
            throw std::out_of_range("Tree is empty.");
        }

        BSTNode<T> *cursor = this->root;
        while (cursor->right != nullptr) {
            cursor = cursor->right;
        }
        return cursor->data;
    }

    template <typename T>
    const T& BinarySearchTree<T>::predecessor(const T& value) {
        return this->_predecessor(this->root, value)->data;
    }

    template <typename T>
    const T& BinarySearchTree<T>::successor(const T& value) {
        return this->_successor(this->root, value)->data;
    }

    template <typename T>
    inline std::size_t BinarySearchTree<T>::size() {
        return this->BSTSize;
    }

    template <typename T>
    inline bool BinarySearchTree<T>::isEmpty() {
        return this->BSTSize == 0;
    }

    template <typename T>
    int BinarySearchTree<T>::height() {
        return this->_height(this->root);
    }

    template <typename T>
    std::string BinarySearchTree<T>::preorder() {
        std::ostringstream outstring;
        this->_preorder(this->root, outstring);
        return outstring.str();
    }

    template <typename T>
    std::string BinarySearchTree<T>::inorder() {
        std::ostringstream outstring;
        this->_inorder(this->root, outstring);
        return outstring.str();
    }

    template <typename T>
    std::string BinarySearchTree<T>::postorder() {
        std::ostringstream outstring;
        this->_postorder(this->root, outstring);
        return outstring.str();
    }

    template <typename T>
    BinarySearchTree<T>::~BinarySearchTree() {
        this->_clear(this->root);
    }
}

#endif // CPPDSA_DATA_STRUCTURE_BINARY_SEARCH_TREE_IPP_