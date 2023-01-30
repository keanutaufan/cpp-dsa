#ifndef CPPDSA_DATA_STRUCTURE_QUEUE_IPP_
#define CPPDSA_DATA_STRUCTURE_QUEUE_IPP_

#include <cstddef>
#include <stdexcept>
#include "Queue.hpp"

namespace DSA {
    template <typename T>
    Queue<T>::Queue() {
        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;
    }

    template <typename T>
    void Queue<T>::enqueue(const T& value) {
        QueueContainer<T>* newElement = new QueueContainer<T>();
        newElement->data = value;
        newElement->next = nullptr;
        
        if (is_empty()) {
            m_head = newElement;
            m_tail = newElement;
        }
        else {
            m_tail->next = newElement;
            m_tail = newElement;
        }

        m_size++;
    }

    template <typename T>
    void Queue<T>::dequeue() {
        if (m_size == 0) {
            throw std::underflow_error("Pop is called on an empty queue.");
        }

        QueueContainer<T>* newHead = m_head->next;
        delete m_head;
        m_head = newHead;
        m_size--;

        if (is_empty()) {
            m_tail = nullptr;
        }
    }

    template <typename T>
    inline const T& Queue<T>::peek_front() const {
        return m_head->data;
    }

    template <typename T>
    inline const T& Queue<T>::peek_back() const {
        return m_tail->data;
    }

    template <typename T>
    inline bool Queue<T>::is_empty() const {
        return m_size == 0;
    }

    template <typename T>
    inline std::size_t Queue<T>::size() const {
        return m_size;
    }


    template <typename T>
    Queue<T>::~Queue() {
        while (!is_empty()) {
            QueueContainer<T>* nextElement = m_head->next;
            delete m_head;
            m_head = nextElement;
            m_size--;
        }
    }
}

#endif // CPPDSA_DATA_STRUCTURE_QUEUE_IPP_