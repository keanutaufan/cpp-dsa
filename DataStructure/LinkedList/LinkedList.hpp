#ifndef CPPDSA_DATA_STRUCTURE_LINKED_LIST_HPP_
#define CPPDSA_DATA_STRUCTURE_LINKED_LIST_HPP_

#include <cstddef>

namespace DSA {

    template <typename T>
    class LinkedList {
    private:
        template <typename U>
        struct LinkedListNode {
            U data;
            LinkedListNode<U>* next;
            LinkedListNode<U>* prev;
        };

        LinkedListNode<T>* head;
        LinkedListNode<T>* tail;
        std::size_t linkedListSize;
        LinkedListNode<T>* _getReference(const std::size_t index);

    public:
        LinkedList();

        void push_front(const T& value);
        void push_back(const T& value);
        void pop_front();
        void pop_back();
        void insertAt(const std::size_t index, const T& value);
        void removeAt(const std::size_t index);

        const T& peek_front();
        const T& peek_back();

        std::size_t size();
        bool isEmpty();

        T& operator[](const std::size_t index);

        ~LinkedList();
    };
}

#include "LinkedList.ipp"

#endif // CPPDSA_DATA_STRUCTURE_LINKED_LIST_HPP_