#ifndef CPPDSA_DATA_STRUCTURE_STACK_IPP_
#define CPPDSA_DATA_STRUCTURE_STACK_IPP_

#include <cstddef>
#include <stdexcept>

#include "Stack.hpp"

namespace DSA {
    template <typename T>
    Stack<T>::Stack() {
        this->top = nullptr;
        this->stackSize = 0;
    }

    template <typename T>
    void Stack<T>::push(const T &value) {
        StackContainer<T>* newNode = new StackContainer<T>();
        newNode->data = value;
        newNode->next = this->top;
        this->top = newNode;
        this->stackSize++;
    }

    template <typename T>
    void Stack<T>::pop() {
        if (this->isEmpty()) {
            throw std::underflow_error("Stack is empty.");
        }

        StackContainer<T>* previousTopElement = this->top;
        this->top = this->top->next;
        delete previousTopElement;
        this->stackSize--;
    }

    template <typename T>
    inline const T& Stack<T>::peek() {
        return this->top->data;
    }

    template <typename T>
    inline bool Stack<T>::isEmpty() {
        return this->stackSize == 0;
    }

    template <typename T>
    inline std::size_t Stack<T>::size() {
        return this->stackSize;
    }

    template <typename T>
    Stack<T>::~Stack() {
        while (!this->isEmpty()) {
            StackContainer<T>* previousTopElement = this->top;
            this->top = this->top->next;
            delete previousTopElement;
            this->stackSize--;
        }
    }
}

#endif // CPPDSA_DATA_STRUCTURE_STACK_IPP_