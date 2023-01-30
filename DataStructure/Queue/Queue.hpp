#ifndef CPPDSA_DATA_STRUCTURE_QUEUE_HPP_
#define CPPDSA_DATA_STRUCTURE_QUEUE_HPP_

#include <cstddef>

namespace DSA {
    template <typename T>
    class Queue {
    private:
        template <typename U>
        struct QueueContainer {
            U data;
            QueueContainer<U>* next;
        };

        QueueContainer<T>* m_head;
        QueueContainer<T>* m_tail;
        std::size_t m_size;

    public:   
        Queue();

        void enqueue(const T& value);
        void dequeue();
        
        const T& peek_front();
        const T& peek_back();

        bool is_empty();
        std::size_t size();

        ~Queue();
    };
}

#include "Queue.ipp"

#endif // CPPDSA_QUEUE_HPP_DATA_STRUCTURE_