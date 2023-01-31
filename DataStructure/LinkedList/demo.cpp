#include <iostream>
#include "LinkedList.hpp"

DSA::LinkedList<int> linkedList;

void printList(const char* expect) {
    std::cout << "===========================" << std::endl;
    std::cout << expect << std::endl;
    std::cout << "Size: " << linkedList.size() << std::endl;
    for (unsigned int i = 0; i < linkedList.size(); i++) {
        std::cout << "LL[" << i << "]: " << linkedList[i] << std::endl;
    }
    std::cout << "===========================" << std::endl;
}

int main() {
    std::cout << "START" << std::endl;
    
    linkedList.push_back(10);
    linkedList.push_front(15);
    linkedList.push_front(5);
    printList("EXPECT: 5, 15, 10");

    linkedList.pop_front();
    linkedList.pop_back();
    printList("EXPECT: 15");

    linkedList.insert_at(0, 10);
    printList("EXPECT: 10, 15");

    linkedList.insert_at(1, 17);
    printList("EXPECT: 10, 17, 15");

    linkedList.insert_at(3, 19);
    printList("EXPECT: 10, 17, 15, 19");

    linkedList.remove_at(1);
    printList("EXPECT: 10, 15, 19");

    std::cout << "FRONT AND BACK PEEK" << std::endl;
    std::cout << linkedList.peek_front() << " " << linkedList.peek_back() << std::endl;  
    std::cout << "Finished!" << std::endl;
    return 0;
}