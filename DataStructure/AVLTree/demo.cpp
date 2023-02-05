#include <iostream>
#include <string>
#include "AVLTree.hpp"

int main() {
    DSA::AVLTree<int, int> avl;
    std::cout << "Initialized AVL Tree" << std::endl;
    std::cout << std::endl;

    avl.insert(30, 30);
    avl.insert(20, 20);
    avl.insert(10, 10);
    avl.insert(40, 40);
    avl.insert(75, 75);
    avl.insert(13, 13);
    avl.insert(12, 12);
    avl.insert(19, 19);
    std::cout << "Inserted {30, 30}, {20, 20}, {10, 10}, {40, 40}, {75, 75}, {13, 13}, {12, 12}, {19, 19} via insert()" << std::endl;
    std::cout << "PREORDER: " << avl.preorder() << std::endl;
    std::cout << "INORDER: " << avl.inorder() << std::endl;
    std::cout << "POSTORDER: " << avl.postorder() << std::endl;
    std::cout << "VALUE OF MIN MAX KEY: " << avl.min() << " " << avl.max() << std::endl;
    std::cout << "SIZE: " << avl.size() << std::endl;
    std::cout << std::endl;
    
    avl.remove(75);
    std::cout << "Removed key 75 via remove()" << std::endl;
    std::cout << "PREORDER: " << avl.preorder() << std::endl;
    std::cout << "INORDER: " << avl.inorder() << std::endl;
    std::cout << "POSTORDER: " << avl.postorder() << std::endl;
    std::cout << "VALUE OF MIN MAX KEY: " << avl.min() << " " << avl.max() << std::endl;
    std::cout << "SIZE: " << avl.size() << std::endl;
    std::cout << std::endl;

    avl[30] = 10;
    avl[75] = 75;
    std::cout << "Modified {30, 30} to {30, 10} and inserted {75, 75} via operator[]" << std::endl;
    std::cout << "PREORDER: " << avl.preorder() << std::endl;
    std::cout << "INORDER: " << avl.inorder() << std::endl;
    std::cout << "POSTORDER: " << avl.postorder() << std::endl;
    std::cout << "VALUE OF MIN MAX KEY: " << avl.min() << " " << avl.max() << std::endl;
    std::cout << "SIZE: " << avl.size() << std::endl;
    std::cout << std::endl;
    
    return 0;
}