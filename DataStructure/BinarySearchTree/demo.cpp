#include <iostream>
#include "BinarySearchTree.hpp"

int compare(const int& a, const int& b) {
    if (a > b) return 1;
    if (a < b) return -1;
    return 0;
}

int main() {

    DSA::BinarySearchTree<int> bst(compare);
    std::cout << "HEIGHT: " << bst.height() << std::endl;
    std::cout << "SIZE: " << bst.size() << std::endl;
    std::cout << "ISEMPTY: " << bst.isEmpty() << std::endl;

    
    bst.insert(10);
    bst.insert(15);
    bst.insert(5);
    bst.insert(17);
    bst.insert(14);
    bst.insert(3);
    bst.insert(1);
    bst.insert(2);
    std::cout << "Added 10, 15, 5, 17, 14, 3, 1, and 2" << std::endl << std::endl;

    std::cout << "Preorder Traversal: " << bst.preorder() << std::endl;
    std::cout << "Inorder Traversal: " << bst.inorder() << std::endl;
    std::cout << "Postorder Traversal: " << bst.postorder() << std::endl;

    bst.remove(3);
    bst.remove(1);
    bst.remove(10);
    bst.remove(15);
    std::cout << "Removed 3, 1, 10 and 15" << std::endl << std::endl;

    for (int i = 0; i <= 20; i++) {
        if (bst.contains(i)) {
            std::cout << bst.search(i) << std::endl;
        }
    }
    

    std::cout << std::endl;
    std::cout << "HEIGHT: " << bst.height() << std::endl;
    std::cout << "SIZE: " << bst.size() << std::endl;
    std::cout << "ISEMPTY: " << bst.isEmpty() << std::endl;
    std::cout << "MIN MAX: " << bst.min() << " " << bst.max() << std::endl;
    std::cout << std::endl;

    std::cout << "Preorder Traversal: " << bst.preorder() << std::endl;
    std::cout << "Inorder Traversal: " << bst.inorder() << std::endl;
    std::cout << "Postorder Traversal: " << bst.postorder() << std::endl;

    std::cout << "Predecessor and Successor of 5 is ";
    std::cout << bst.predecessor(5) << " and " << bst.successor(5) << std::endl;
    return 0;
}