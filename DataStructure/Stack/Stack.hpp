#ifndef CPPDSA_DATA_STRUCTURE_STACK_HPP_
#define CPPDSA_DATA_STRUCTURE_STACK_HPP_

#include <cstddef>

namespace DSA {

    template <typename T>
    class Stack {
    private:
        template <typename U>
        struct StackNode {
            U data;
            StackNode<U>* next;
        };

        StackNode<T>* m_top;
        std::size_t m_size;

    public:
        Stack();

        void push(const T& value);
        void pop();

        const T& peek() const;

        bool is_empty() const;
        std::size_t size() const;

        ~Stack();
    };
}

#include "Stack.ipp"

#endif // CPPDSA_DATA_STRUCTURE_STACK_HPP_