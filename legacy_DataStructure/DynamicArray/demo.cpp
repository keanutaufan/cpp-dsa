#include <iostream>
#include "DynamicArray.hpp"

int main() {
    DSA::DynamicArray<int> array;

    std::cout << "Initialization" << std::endl;
    std::cout << "Array size/cap: " << array.size() << " " << array.capacity() << std::endl;
    std::cout << std::endl;

    array.push_back(0);
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);
    array.push_back(6);
    array.push_back(7);
    std::cout << "Inserted element [0,1,2,3,4,5,6,7] via push_back()" << std::endl;
    std::cout << "Array size/cap: " << array.size() << " " << array.capacity() << std::endl << std::endl;
    for (unsigned int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }


    array.insert_at(6, 100);
    std::cout << "Inserted element [100] at index 6 via insert_at()" << std::endl;
    std::cout << "Array size/cap: " << array.size() << " " << array.capacity() << std::endl;
    for (unsigned int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;

    
    array.insert_at(6, 75);
    array.insert_at(6, 50);
    array.insert_at(6, 40);
    std::cout << "Inserted element [75], then [50], then [40] at index 6 via insert_at()" << std::endl;
    std::cout << "Array size/cap: " << array.size() << " " << array.capacity() << std::endl;
    for (unsigned int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;


    array.remove_at(6);
    std::cout << "Removed element at index 6 via remove_at" << std::endl;
    std::cout << "Array size/cap: " << array.size() << " " << array.capacity() << std::endl;
    for (unsigned int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;


    array.insert_at(6, -30, 2);
    std::cout << "Inserted 2 copies of element [30] at index 6 via insert_at" << std::endl;
    std::cout << "Array size/cap: " << array.size() << " " << array.capacity() << std::endl;
    for (unsigned int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;


    array.remove_at(6, 2);
    std::cout << "Removed 2 elements starting from index 6 via remove_at()" << std::endl;
    std::cout << "Array size/cap: " << array.size() << " " << array.capacity() << std::endl;
    for (unsigned int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;


    array.shrink_to_fit();
    std::cout << "Shrank array to fit its current size via shrink_to_fit()" << std::endl;
    std::cout << "Array size/cap: " << array.size() << " " << array.capacity() << std::endl;
    for (unsigned int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;


    array.resize(5);
    std::cout << "Resized array to 5 elements via resize()" << std::endl;
    std::cout << "Array size/cap: " << array.size() << " " << array.capacity() << std::endl;
    for (unsigned int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;


    array.resize(10);
    std::cout << "Resized array to 10 elements via resize()" << std::endl;
    std::cout << "Array size/cap: " << array.size() << " " << array.capacity() << std::endl;
    for (unsigned int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;


    array.insert_at(9, 10, 3);
    std::cout << "Inserted 3 copies of element [10] at index 9 via insert_at()" << std::endl;
    std::cout << "Array size/cap: " << array.size() << " " << array.capacity() << std::endl;
    for (unsigned int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;


    array.resize(15);
    std::cout << "Resized array to 15 elements via resize()" << std::endl;
    std::cout << "Array size/cap: " << array.size() << " " << array.capacity() << std::endl;
    for (unsigned int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;


    array.pop_back();
    std::cout << "Popped an element from the back via pop_back()" << std::endl;
    std::cout << "Array size/cap: " << array.size() << " " << array.capacity() << std::endl;
    for (unsigned int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;


    array.remove_at(10, 4);
    std::cout << "Removed 4 last elements via remove_at()" << std::endl;
    std::cout << "Array size/cap: " << array.size() << " " << array.capacity() << std::endl;
    for (unsigned int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;


    array.resize(10);
    std::cout << "Resized array to 10 elements via resize()" << std::endl;
    std::cout << "Array size/cap: " << array.size() << " " << array.capacity() << std::endl;
    for (unsigned int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;


    array.push_back(15);
    std::cout << "Pushed element [15] to the array via push_back()" << std::endl;
    std::cout << "Array size/cap: " << array.size() << " " << array.capacity() << std::endl;
    for (unsigned int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;


    array.clear();
    std::cout << "Cleared the array via clear() (NOTE: capacity must remain the same)" << std::endl;
    std::cout << "Array size/cap: " << array.size() << " " << array.capacity() << std::endl;
    for (unsigned int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;


    return 0;
}