#ifndef CPPDSA_DATA_STRUCTURE_DEQUE_HPP_
#define CPPDSA_DATA_STRUCTURE_DEQUE_HPP_

#include <cstddef>

namespace DSA {
    template <typename T>
    class Deque {
    private:
        template <typename U>
        struct DequeContainer {
            U data;
            DequeContainer<U>* next;
            DequeContainer<U>* prev;
        };

        DequeContainer<T>* head;
        DequeContainer<T>* tail;
        std::size_t dequeSize;

    public:
        Deque();

        void push_front(const T& value);
        void push_back(const T& value);
        void pop_front();
        void pop_back();

        const T& peek_front();
        const T& peek_back();

        bool isEmpty();
        std::size_t size();

        ~Deque();
    };
}

#include "Deque.ipp"

#endif // CPPDSA_DATA_STRUCTURE_DEQUE_HPP_