#ifndef CPPDSA_DATA_STRUCTURE_DEQUE_HPP_
#define CPPDSA_DATA_STRUCTURE_DEQUE_HPP_

#include <cstddef>

namespace DSA {
    template <typename T>
    class Deque {
    private:
        template <typename U>
        struct DequeNode {
            U data;
            DequeNode<U>* next;
            DequeNode<U>* prev;
        };

        DequeNode<T>* m_head;
        DequeNode<T>* m_tail;
        std::size_t m_size;

    public:
        Deque();

        void push_front(const T& value);
        void push_back(const T& value);
        void pop_front();
        void pop_back();

        const T& peek_front() const;
        const T& peek_back() const;

        bool is_empty() const;
        std::size_t size() const;

        ~Deque();
    };
}

#include "Deque.ipp"

#endif // CPPDSA_DATA_STRUCTURE_DEQUE_HPP_