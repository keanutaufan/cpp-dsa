#ifndef CPPDSA_DATA_STRUCTURE_PRIORITY_QUEUE_HPP_
#define CPPDSA_DATA_STRUCTURE_PRIORITY_QUEUE_HPP_

#include <cstddef>
#include "../DynamicArray/DynamicArray.hpp"

namespace DSA {
    template <typename T>
    class PriorityQueue {
    private:
        DynamicArray<T> m_data;
        int (*_compare)(const T& value1, const T& value2);

    public:
        PriorityQueue(int (*comparator)(const T& value1, const T& value2) = max_queue);

        static int min_queue(const T& value1, const T& value2);
        static int max_queue(const T& value1, const T& value2);

        void insert(const T& value);
        void pull();

        const T& peek() const;

        bool is_empty() const;
        std::size_t size() const;

        ~PriorityQueue();
    };
}

#include "PriorityQueue.ipp"

#endif // CPPDSA_DATA_STRUCTURE_PRIORITY_QUEUE_HPP_