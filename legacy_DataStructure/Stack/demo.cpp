#include <iostream>
#include "Stack.hpp"

int main() {
    // Declare a stack of integers that will contain user data
    DSA::Stack<int> stack;

    // Push 5 elements into the stack
    stack.push(10);
    std::cout << "Pushed element 10 into the stack" << std::endl;

    stack.push(5);
    std::cout << "Pushed element 5 into the stack" << std::endl;

    stack.push(7);
    std::cout << "Pushed element 7 into the stack" << std::endl;

    stack.push(4);
    std::cout << "Pushed element 4 into the stack" << std::endl;

    stack.push(3);
    std::cout << "Pushed element 3 into the stack" << std::endl;

    // Print out stack size
    std::cout << "Stack size: " << stack.size() << std::endl;

    // Print out stack elements
    std::cout << "Stack elements: " << std::endl;
    while (!stack.is_empty()) {
        std::cout << stack.size() << " : " << stack.peek() << std::endl;
        stack.pop();
    }
    return 0;
}