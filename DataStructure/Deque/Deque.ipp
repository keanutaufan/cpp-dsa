#ifndef CPPDSA_DATA_STRUCTURE_DEQUE_IPP_
#define CPPDSA_DATA_STRUCTURE_DEQUE_IPP_

#include <cstddef>
#include <stdexcept>
#include "Deque.hpp"

namespace DSA {
    template <typename T>
    Deque<T>::Deque() {
        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;
    }

    template <typename T>
    void Deque<T>::push_front(const T& value) {
        DequeContainer<T>* newElement = new DequeContainer<T>();
        newElement->data = value;
        newElement->next = nullptr;
        newElement->prev = nullptr;

        if (is_empty()) {
            m_head = newElement;
            m_tail = newElement;
        }
        else {
            newElement->next = m_head;
            m_head->prev = newElement;
            m_head = newElement;
        }

        m_size++;
    }

    template <typename T>
    void Deque<T>::push_back(const T& value) {
        DequeContainer<T>* newElement = new DequeContainer<T>();
        newElement->data = value;
        newElement->next = nullptr;
        newElement->prev = nullptr;

        if (is_empty()) {
            m_head = newElement;
            m_tail = newElement;
        }
        else {
            newElement->prev = m_tail;
            m_tail->next = newElement;
            m_tail = newElement;
        }

        m_size++;
    }

    template <typename T>
    void Deque<T>::pop_front() {
        if (m_size == 0) {
            throw std::underflow_error("Deque is empty.");
        }
        else if (m_size == 1) {
            delete m_head;
            m_head = nullptr;
            m_tail = nullptr;
        }
        else {
            DequeContainer<T>* newHead = m_head->next;
            newHead->prev = nullptr;
            delete m_head;
            m_head = newHead;
        }

        m_size--;
    }

    template <typename T>
    void Deque<T>::pop_back() {
        if (m_size == 0) {
            throw std::underflow_error("Deque is empty.");
        }
        else if (m_size == 1) {
            delete m_tail;
            m_head = nullptr;
            m_tail = nullptr;
        }
        else {
            DequeContainer<T>* newTail = m_tail->prev;
            newTail->next = nullptr;
            delete m_tail;
            m_tail = newTail;
        }

        m_size--;
    }

    template <typename T>
    inline const T& Deque<T>::peek_front() const {
        return m_head->data;
    }

    template <typename T>
    inline const T& Deque<T>::peek_back() const {
        return m_tail->data;
    }

    template <typename T>
    inline bool Deque<T>::is_empty() const {
        return m_size == 0;
    }

    template <typename T>
    inline std::size_t Deque<T>::size() const {
        return m_size;
    }

    template <typename T>
    Deque<T>::~Deque() {
        DequeContainer<T>* currentElement = m_head;
        while (currentElement != nullptr) {
            DequeContainer<T>* nextElement = currentElement->next;
            delete currentElement;
            currentElement = nextElement;
        }
    }
}

#endif // CPPDSA_DATA_STRUCTURE_DEQUE_IPP_