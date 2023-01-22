#ifndef CPPDSA_DATA_STRUCTURE_QUEUE_IPP_
#define CPPDSA_DATA_STRUCTURE_QUEUE_IPP_

#include <cstddef>
#include <stdexcept>
#include "Queue.hpp"

namespace DSA {
    template <typename T>
    Queue<T>::Queue() {
        this->head = nullptr;
        this->tail = nullptr;
        this->queueSize = 0;
    }

    template <typename T>
    void Queue<T>::enqueue(const T& value) {
        QueueContainer<T>* newElement = new QueueContainer<T>();
        newElement->data = value;
        newElement->next = nullptr;
        
        if (this->isEmpty()) {
            this->head = newElement;
            this->tail = newElement;
        }
        else {
            this->tail->next = newElement;
            this->tail = newElement;
        }

        this->queueSize++;
    }

    template <typename T>
    void Queue<T>::dequeue() {
        if (this->queueSize == 0) {
            throw std::underflow_error("Pop is called on an empty queue.");
        }

        QueueContainer<T>* newHead = this->head->next;
        delete this->head;
        this->head = newHead;
        this->queueSize--;

        if (this->isEmpty()) {
            this->tail = nullptr;
        }
    }

    template <typename T>
    inline const T& Queue<T>::peek_front() {
        return this->head->data;
    }

    template <typename T>
    inline const T& Queue<T>::peek_back() {
        return this->tail->data;
    }

    template <typename T>
    inline bool Queue<T>::isEmpty() {
        return this->queueSize == 0;
    }

    template <typename T>
    inline std::size_t Queue<T>::size() {
        return this->queueSize;
    }


    template <typename T>
    Queue<T>::~Queue() {
        while (!this->isEmpty()) {
            QueueContainer<T>* nextElement = this->head->next;
            delete this->head;
            this->head = nextElement;
            this->queueSize--;
        }
    }
}

#endif // CPPDSA_DATA_STRUCTURE_QUEUE_IPP_