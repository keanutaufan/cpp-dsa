#ifndef CPPDSA_DATA_STRUCTURE_DEQUE_IPP_
#define CPPDSA_DATA_STRUCTURE_DEQUE_IPP_

#include <cstddef>
#include <stdexcept>
#include "Deque.hpp"

namespace DSA {
    template <typename T>
    Deque<T>::Deque() {
        this->head = nullptr;
        this->tail = nullptr;
        this->dequeSize = 0;
    }

    template <typename T>
    void Deque<T>::push_front(const T& value) {
        DequeContainer<T>* newElement = new DequeContainer<T>();
        newElement->data = value;
        newElement->next = nullptr;
        newElement->prev = nullptr;

        if (this->isEmpty()) {
            this->head = newElement;
            this->tail = newElement;
        }
        else {
            newElement->next = this->head;
            this->head->prev = newElement;
            this->head = newElement;
        }

        this->dequeSize++;
    }

    template <typename T>
    void Deque<T>::push_back(const T& value) {
        DequeContainer<T>* newElement = new DequeContainer<T>();
        newElement->data = value;
        newElement->next = nullptr;
        newElement->prev = nullptr;

        if (this->isEmpty()) {
            this->head = newElement;
            this->tail = newElement;
        }
        else {
            newElement->prev = this->tail;
            this->tail->next = newElement;
            this->tail = newElement;
        }

        this->dequeSize++;
    }

    template <typename T>
    void Deque<T>::pop_front() {
        if (this->dequeSize == 0) {
            throw std::underflow_error("Deque is empty.");
        }
        else if (this->dequeSize == 1) {
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
        }
        else {
            DequeContainer<T>* newHead = this->head->next;
            newHead->prev = nullptr;
            delete this->head;
            this->head = newHead;
        }

        this->dequeSize--;
    }

    template <typename T>
    void Deque<T>::pop_back() {
        if (this->dequeSize == 0) {
            throw std::underflow_error("Deque is empty.");
        }
        else if (this->dequeSize == 1) {
            delete this->tail;
            this->head = nullptr;
            this->tail = nullptr;
        }
        else {
            DequeContainer<T>* newTail = this->tail->prev;
            newTail->next = nullptr;
            delete this->tail;
            this->tail = newTail;
        }

        this->dequeSize--;
    }

    template <typename T>
    inline const T& Deque<T>::peek_front() {
        return this->head->data;
    }

    template <typename T>
    inline const T& Deque<T>::peek_back() {
        return this->tail->data;
    }

    template <typename T>
    inline bool Deque<T>::isEmpty() {
        return this->dequeSize == 0;
    }

    template <typename T>
    inline std::size_t Deque<T>::size() {
        return this->dequeSize;
    }

    template <typename T>
    Deque<T>::~Deque() {
        DequeContainer<T>* currentElement = this->head;
        while (currentElement != nullptr) {
            DequeContainer<T>* nextElement = currentElement->next;
            delete currentElement;
            currentElement = nextElement;
        }
    }
}

#endif // CPPDSA_DATA_STRUCTURE_DEQUE_IPP_