#ifndef CPPDSA_DATA_STRUCTURELINKED_LIST_IPP_
#define CPPDSA_DATA_STRUCTURELINKED_LIST_IPP_

#include <cstddef>
#include <stdexcept>
#include "LinkedList.hpp"

namespace DSA {
    template <typename T>
    LinkedList<T>::LinkedListNode<T>* LinkedList<T>::_get_reference(const std::size_t index) {
    if (index < 0 || index >= m_size) {
            throw std::out_of_range("Index out of range.");
        }

        LinkedListNode<T>* cursor = nullptr;

        if (index <= m_size/2) {
            cursor = m_head;
            for (std::size_t i = 0; i < index; i++) {
                cursor = cursor->next;
            }
        }
        else {
            cursor = m_tail;
            for (std::size_t i = m_size-1; i > index; i--) {
                cursor = cursor->prev;
            }
        }

        return cursor;
    }

    template <typename T>
    LinkedList<T>::LinkedList() {
        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;
    }

    template <typename T>
    void LinkedList<T>::push_front(const T& value) {
        LinkedListNode<T>* newElement = new LinkedListNode<T>();
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
    void LinkedList<T>::push_back(const T& value) {
        LinkedListNode<T>* newElement = new LinkedListNode<T>();
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
    void LinkedList<T>::pop_front() {
        if (is_empty()) {
            throw std::underflow_error("List is empty.");
        }

        LinkedListNode<T>* newHead = m_head->next;
        delete m_head;
        m_head = newHead;
        m_head->prev = nullptr;
        m_size--;

        if (is_empty()) {
            m_tail = nullptr;
        }
    }

    template <typename T>
    void LinkedList<T>::pop_back() {
        if (is_empty()) {
            throw std::underflow_error("List is empty.");
        }

        LinkedListNode<T>* newTail = m_tail->prev;
        delete m_tail;
        m_tail = newTail;
        m_tail->next = nullptr;
        m_size--;

        if (is_empty()) {
            m_head = nullptr;
        }
    }

    template <typename T>
    void LinkedList<T>::insert_at(const std::size_t index, const T& value) {
        if (index == 0) {
            push_front(value);
        }
        else if (index == m_size) {
            push_back(value);
        }
        else {
            LinkedListNode<T>* proceedingElement = _get_reference(index);
            LinkedListNode<T>* preceedingElement = proceedingElement->prev;

            LinkedListNode<T>* newElement = new LinkedListNode<T>();
            newElement->data = value;
            newElement->next = proceedingElement;
            newElement->prev = preceedingElement;
            
            preceedingElement->next = newElement;
            proceedingElement->prev = newElement;

            m_size++;
        }
    }

    template <typename T>
    void LinkedList<T>::remove_at(const std::size_t index) {
        if (index >= m_size) {
            throw std::out_of_range("Remove on out of range index.");
        }
        
        if (index == 0) {
            pop_front();
        }
        else if (index == m_size-1) {
            pop_back();
        }
        else {
            LinkedListNode<T>* elementToRemove = _get_reference(index);
            LinkedListNode<T>* preceedingElement = elementToRemove->prev;
            LinkedListNode<T>* proceedingElement = elementToRemove->next;

            preceedingElement->next = proceedingElement;
            proceedingElement->prev = preceedingElement;
            delete elementToRemove;

            m_size--;
        }
    }

    template <typename T>
    inline const T& LinkedList<T>::peek_front() const {
        return m_head->data;
    }

    template <typename T>
    inline const T& LinkedList<T>::peek_back() const{
        return m_tail->data;
    }

    template <typename T>
    inline std::size_t LinkedList<T>::size() const {
        return m_size;
    }

    template <typename T>
    inline bool LinkedList<T>::is_empty() const {
        return m_size == 0;
    }

    template <typename T>
    T& LinkedList<T>::operator[](const std::size_t index) {
        return _get_reference(index)->data;
    }

    template <typename T>
    LinkedList<T>::~LinkedList() {
        while (!is_empty()) {
            LinkedListNode<T>* headElement = m_head;
            m_head = m_head->next;
            delete headElement;
            m_size--;
        }
    }

}

#endif // CPPDSA_DATA_STRUCTURE_LINKED_LIST_IPP_