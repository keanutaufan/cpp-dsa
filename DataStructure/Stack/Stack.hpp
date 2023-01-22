#ifndef CPPDSA_DATA_STRUCTURE_STACK_HPP_
#define CPPDSA_DATA_STRUCTURE_STACK_HPP_

#include <cstddef>

namespace DSA {

    template <typename T>
    class Stack {
    private:
        template <typename U>
        struct StackContainer {
            U data;
            StackContainer<U>* next;
        };

        StackContainer<T>* top;
        std::size_t stackSize;

    public:
        Stack();

        void push(const T& value);
        void pop();

        const T& peek();

        bool isEmpty();
        std::size_t size();

        ~Stack();
    };
}

#include "Stack.ipp"

#endif // CPPDSA_DATA_STRUCTURE_STACK_HPP_