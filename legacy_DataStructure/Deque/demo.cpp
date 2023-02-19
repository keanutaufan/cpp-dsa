#include <iostream>
#include "Deque.hpp"

DSA::Deque<int> deque;

void printDeque(const char* expect) {
    std::cout << "========================================" << std::endl;
    std::cout << expect << std::endl;
    std::cout << "| SIZE: " << deque.size() << " | FRONT: " << deque.peek_front() << " | BACK: " << deque.peek_back() << " |" << std::endl;
    std::cout << "========================================" << std::endl;
}

int main() {
    deque.push_back(10);
    printDeque("EXPECT: ( 1, 10, 10 )");

    deque.push_front(15);
    printDeque("EXPECT: ( 2, 15, 10 )");

    deque.pop_back();
    printDeque("EXPECT: ( 1, 15, 15 )");
    return 0;
}