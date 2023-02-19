#ifndef CPPDSA_DATA_STRUCTURE_STACK_IPP_
#define CPPDSA_DATA_STRUCTURE_STACK_IPP_

#include <cstddef>
#include <stdexcept>

#include "Stack.hpp"

namespace DSA {
    template <typename T>
    Stack<T>::Stack() {
        m_top = nullptr;
        m_size = 0;
    }

    template <typename T>
    void Stack<T>::push(const T &value) {
        StackNode<T>* newNode = new StackNode<T>();
        newNode->data = value;
        newNode->next = m_top;
        m_top = newNode;
        m_size++;
    }

    template <typename T>
    void Stack<T>::pop() {
        if (is_empty()) {
            throw std::underflow_error("Stack is empty.");
        }

        StackNode<T>* previousTopElement = m_top;
        m_top = m_top->next;
        delete previousTopElement;
        m_size--;
    }

    template <typename T>
    inline const T& Stack<T>::peek() const {
        return m_top->data;
    }

    template <typename T>
    inline bool Stack<T>::is_empty() const {
        return m_size == 0;
    }

    template <typename T>
    inline std::size_t Stack<T>::size() const {
        return m_size;
    }

    template <typename T>
    Stack<T>::~Stack() {
        while (!is_empty()) {
            StackNode<T>* previousTopElement = m_top;
            m_top = m_top->next;
            delete previousTopElement;
            m_size--;
        }
    }
}

#endif // CPPDSA_DATA_STRUCTURE_STACK_IPP_