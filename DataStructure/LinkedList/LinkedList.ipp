#ifndef CPPDSA_DATA_STRUCTURELINKED_LIST_IPP_
#define CPPDSA_DATA_STRUCTURELINKED_LIST_IPP_

#include <cstddef>
#include <stdexcept>
#include "LinkedList.hpp"

namespace DSA {
    template <typename T>
    LinkedList<T>::LinkedListNode<T>* LinkedList<T>::_getReference(const std::size_t index) {
    if (index < 0 || index >= this->linkedListSize) {
            throw std::out_of_range("Index out of range.");
        }

        LinkedListNode<T>* cursor = nullptr;

        if (index <= this->linkedListSize/2) {
            cursor = this->head;
            for (std::size_t i = 0; i < index; i++) {
                cursor = cursor->next;
            }
        }
        else {
            cursor = this->tail;
            for (std::size_t i = this->linkedListSize-1; i > index; i--) {
                cursor = cursor->prev;
            }
        }

        return cursor;
    }

    template <typename T>
    LinkedList<T>::LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->linkedListSize = 0;
    }

    template <typename T>
    void LinkedList<T>::push_front(const T& value) {
        LinkedListNode<T>* newElement = new LinkedListNode<T>();
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

        this->linkedListSize++;
    }    

    template <typename T>
    void LinkedList<T>::push_back(const T& value) {
        LinkedListNode<T>* newElement = new LinkedListNode<T>();
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

        this->linkedListSize++;
    }

    template <typename T>
    void LinkedList<T>::pop_front() {
        if (this->isEmpty()) {
            throw std::underflow_error("List is empty.");
        }

        LinkedListNode<T>* newHead = this->head->next;
        delete this->head;
        this->head = newHead;
        this->head->prev = nullptr;
        this->linkedListSize--;

        if (this->isEmpty()) {
            this->tail = nullptr;
        }
    }

    template <typename T>
    void LinkedList<T>::pop_back() {
        if (this->isEmpty()) {
            throw std::underflow_error("List is empty.");
        }

        LinkedListNode<T>* newTail = this->tail->prev;
        delete this->tail;
        this->tail = newTail;
        this->tail->next = nullptr;
        this->linkedListSize--;

        if (this->isEmpty()) {
            this->head = nullptr;
        }
    }

    template <typename T>
    void LinkedList<T>::insertAt(const std::size_t index, const T& value) {
        if (index == 0) {
            this->push_front(value);
        }
        else if (index == this->linkedListSize) {
            this->push_back(value);
        }
        else {
            LinkedListNode<T>* proceedingElement = this->_getReference(index);
            LinkedListNode<T>* preceedingElement = proceedingElement->prev;

            LinkedListNode<T>* newElement = new LinkedListNode<T>();
            newElement->data = value;
            newElement->next = proceedingElement;
            newElement->prev = preceedingElement;
            
            preceedingElement->next = newElement;
            proceedingElement->prev = newElement;

            this->linkedListSize++;
        }
    }

    template <typename T>
    void LinkedList<T>::removeAt(const std::size_t index) {
        if (index >= this->linkedListSize) {
            throw std::out_of_range("Remove on out of range index.");
        }
        
        if (index == 0) {
            this->pop_front();
        }
        else if (index == this->linkedListSize-1) {
            this->pop_back();
        }
        else {
            LinkedListNode<T>* elementToRemove = this->_getReference(index);
            LinkedListNode<T>* preceedingElement = elementToRemove->prev;
            LinkedListNode<T>* proceedingElement = elementToRemove->next;

            preceedingElement->next = proceedingElement;
            proceedingElement->prev = preceedingElement;
            delete elementToRemove;

            this->linkedListSize--;
        }
    }

    template <typename T>
    inline const T& LinkedList<T>::peek_front() {
        return this->head->data;
    }

    template <typename T>
    inline const T& LinkedList<T>::peek_back() {
        return this->tail->data;
    }

    template <typename T>
    inline std::size_t LinkedList<T>::size() {
        return this->linkedListSize;
    }

    template <typename T>
    inline bool LinkedList<T>::isEmpty() {
        return this->linkedListSize == 0;
    }

    template <typename T>
    T& LinkedList<T>::operator[](const std::size_t index) {
        return this->_getReference(index)->data;
    }

    template <typename T>
    LinkedList<T>::~LinkedList() {
        while (!this->isEmpty()) {
            LinkedListNode<T>* headElement = this->head;
            this->head = this->head->next;
            delete headElement;
            this->linkedListSize--;
        }
    }

}

#endif // CPPDSA_DATA_STRUCTURE_LINKED_LIST_IPP_