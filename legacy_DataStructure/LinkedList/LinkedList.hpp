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

        LinkedListNode<T>* m_head;
        LinkedListNode<T>* m_tail;
        std::size_t m_size;
        LinkedListNode<T>* _get_reference(const std::size_t index);

    public:
        LinkedList();

        void push_front(const T& value);
        void push_back(const T& value);
        void pop_front();
        void pop_back();
        void insert_at(const std::size_t index, const T& value);
        void remove_at(const std::size_t index);

        const T& peek_front() const;
        const T& peek_back() const;

        std::size_t size() const;
        bool is_empty() const;

        T& operator[](const std::size_t index);

        ~LinkedList();
    };
}

#include "LinkedList.ipp"

#endif // CPPDSA_DATA_STRUCTURE_LINKED_LIST_HPP_