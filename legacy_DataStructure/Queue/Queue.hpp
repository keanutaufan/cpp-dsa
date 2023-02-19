#ifndef CPPDSA_DATA_STRUCTURE_QUEUE_HPP_
#define CPPDSA_DATA_STRUCTURE_QUEUE_HPP_

#include <cstddef>

namespace DSA {
    template <typename T>
    class Queue {
    private:
        template <typename U>
        struct QueueNode {
            U data;
            QueueNode<U>* next;
        };

        QueueNode<T>* m_head;
        QueueNode<T>* m_tail;
        std::size_t m_size;

    public:   
        Queue();

        void enqueue(const T& value);
        void dequeue();
        
        const T& peek_front() const;
        const T& peek_back() const;

        bool is_empty() const;
        std::size_t size() const;

        ~Queue();
    };
}

#include "Queue.ipp"

#endif // CPPDSA_QUEUE_HPP_DATA_STRUCTURE_