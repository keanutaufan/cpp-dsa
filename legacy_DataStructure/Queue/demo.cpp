#include <iostream>
#include "Queue.hpp"

int main() {
    DSA::Queue<int> queue;
    queue.enqueue(15);
    std::cout << queue.peek_front() << " " << queue.peek_back() << std::endl;
    queue.enqueue(25);
    std::cout << queue.peek_front() << " " << queue.peek_back() << std::endl;
    queue.enqueue(35);
    std::cout << queue.peek_front() << " " << queue.peek_back() << std::endl;
    queue.dequeue();
    std::cout << queue.peek_front() << " " << queue.peek_back() << std::endl;
    queue.dequeue();
    std::cout << queue.peek_front() << " " << queue.peek_back() << std::endl;
    queue.dequeue();
    std::cout << queue.size() << std::endl;

    queue.enqueue(10);
    queue.enqueue(5);
    queue.enqueue(15);
    std::cout << queue.peek_front() << " " << queue.peek_back() << std::endl;
    queue.dequeue();

    return 0;
}