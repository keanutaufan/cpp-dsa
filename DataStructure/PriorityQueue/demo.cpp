#include <iostream>
#include "PriorityQueue.hpp"

int main() {
    DSA::PriorityQueue<int> pq(DSA::PriorityQueue<int>::min_queue);
    std::cout << "Priority Queue is initialized" << std::endl;
    std::cout << "PQ Size: " << pq.size() << std::endl << std::endl;

    pq.insert(10);
    std::cout << "10 is Inserted to PQ via insert()" << std::endl;
    std::cout << "PQ Size: " << pq.size() << " | Top: " << pq.peek() << std::endl << std::endl;
    
    pq.insert(20);
    std::cout << "20 is Inserted to PQ via insert()" << std::endl;
    std::cout << "PQ Size: " << pq.size() << " | Top: " << pq.peek() << std::endl << std::endl;
    
    pq.insert(5);
    std::cout << "5 is Inserted to PQ via insert()" << std::endl;
    std::cout << "PQ Size: " << pq.size() << " | Top: " << pq.peek() << std::endl << std::endl;

    pq.pull();
    std::cout << "An element is pulled from the PQ via pull()" << std::endl;
    std::cout << "PQ Size: " << pq.size() << " | Top: " << pq.peek() << std::endl << std::endl;
    
    pq.pull();
    std::cout << "An element is pulled from the PQ via pull()" << std::endl;
    std::cout << "PQ Size: " << pq.size() << " | Top: " << pq.peek() << std::endl << std::endl;

    pq.insert(15);
    pq.insert(30);
    pq.insert(35);
    std::cout << "15, 30, and 35 are inserted to PQ via insert()" << std::endl;
    std::cout << "PQ Size: " << pq.size() << " | Top: " << pq.peek() << std::endl << std::endl;

    pq.pull();
    std::cout << "An element is pulled from the PQ via pull()" << std::endl;
    std::cout << "PQ Size: " << pq.size() << " | Top: " << pq.peek() << std::endl << std::endl;
    return 0;
}