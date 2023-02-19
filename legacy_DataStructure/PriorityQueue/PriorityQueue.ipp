#ifndef CPPDSA_DATA_STRUCTURE_PRIORITY_QUEUE_IPP_
#define CPPDSA_DATA_STRUCTURE_PRIORITY_QUEUE_IPP_

#include <cstddef>
#include <stdexcept>
#include <utility>
#include "../DynamicArray/DynamicArray.hpp"
#include "PriorityQueue.hpp"

namespace DSA {
    template <typename T>
    PriorityQueue<T>::PriorityQueue(int (*comparator)(const T &value1, const T& value2)) {
        _compare = comparator;
    }

    template <typename T>
    int PriorityQueue<T>::min_queue(const T& value1, const T& value2) {
        if (value1 > value2) {
            return -1;
        }
        else if (value1 < value2) {
            return 1;
        }
        else {
            return 0;
        }
    }

    template <typename T>
    int PriorityQueue<T>::max_queue(const T& value1, const T& value2) {
        if (value1 > value2) {
            return 1;
        }
        else if (value1 < value2) {
            return -1;
        }
        else {
            return 0;
        }
    }

    template <typename T>
    void PriorityQueue<T>::insert(const T& value) {
        m_data.push_back(value);
        std::size_t current = m_data.size() - 1;
        std::size_t parent = (current - 1) / 2;
        while (current > 0 && _compare(m_data[current], m_data[parent]) > 0) {
            std::swap(m_data[current], m_data[parent]);
            current = parent;
            parent = (current - 1) / 2;
        }
    }
    
    template <typename T>
    void PriorityQueue<T>::pull() {
        if (is_empty()) {
            throw std::underflow_error("Queue is empty.");
        }

        std::swap(m_data.front(), m_data.back());
        m_data.pop_back();

        std::size_t current = 0;
        std::size_t leftChild = 2 * current + 1;
        std::size_t rightChild = 2 * current + 2;
        std::size_t higherPriority;

        while (leftChild < m_data.size()) {
            if (rightChild < m_data.size()) {
                higherPriority = (_compare(m_data[leftChild], m_data[rightChild]) > 0) ? leftChild : rightChild;
            }
            else {
                higherPriority = leftChild;
            }
            
            if (_compare(m_data[current], m_data[higherPriority]) > 0) {
                break;
            }

            std::swap(m_data[current], m_data[higherPriority]);
            current = higherPriority;
            leftChild = 2 * current + 1;
            rightChild = 2 * current + 2;
        }
    }

    template <typename T>
    const T& PriorityQueue<T>::peek() const {
        if (is_empty()) {
            throw std::out_of_range("Queue is empty.");
        }
        return m_data.front();
    }

    template <typename T>
    inline bool PriorityQueue<T>::is_empty() const {
        return m_data.is_empty();
    }

    template <typename T>
    inline std::size_t PriorityQueue<T>::size() const {
        return m_data.size();
    }

    template <typename T>
    PriorityQueue<T>::~PriorityQueue() {
        m_data.~DynamicArray();
    }
}

#endif // CPPDSA_DATA_STRUCTURE_PRIORITY_QUEUE_IPP_