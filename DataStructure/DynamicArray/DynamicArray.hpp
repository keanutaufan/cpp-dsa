#ifndef CPPDSA_DATA_STRUCTURE_DYNAMIC_ARRAY_HPP_
#define CPPDSA_DATA_STRUCTURE_DYNAMIC_ARRAY_HPP_

#include <cstddef>
#include <type_traits>

namespace DSA {

    template <typename T>
    class DynamicArray {
    private:
        const std::size_t _DYNAMIC_ARRAY_INIT_SIZE = 8;
        const std::size_t _DYNAMIC_ARRAY_GROWTH_FACTOR = 2;
        const bool _IS_TYPE_POINTER = std::is_pointer<T>::value;

    private:
        T* m_buffer;
        std::size_t m_size;
        std::size_t m_capacity;

        void _resize(const std::size_t newSize);
        void _shift_right(const std::size_t startPos, const std::size_t count);
        void _shift_left(const std::size_t startPos, const std::size_t count);

    public:
        DynamicArray();

        void push_back(const T& value);
        void pop_back();
        void insert_at(const std::size_t index, const T& value);
        void insert_at(const std::size_t index, const T& value, const std::size_t count);
        void remove_at(const std::size_t index);
        void remove_at(const std::size_t index, const std::size_t count);
        void resize(const std::size_t count);
        void resize(const std::size_t count, const T& value);
        void clear();

        bool is_empty() const;
        std::size_t size() const;
        std::size_t capacity() const;
        void reserve(const std::size_t newCapacity);
        void shrink_to_fit();

        T& front();
        const T& front() const;
        T& back();
        const T& back() const;
        T& at(const std::size_t index);
        const T& at(const std::size_t index) const;
        T& operator[](const std::size_t index);
        const T& operator[](const std::size_t index) const;
        T* data();
        const T* data() const;

        ~DynamicArray();
    };
}

#include "DynamicArray.ipp"

#endif // CPPDSA_DATA_STRUCTURE_DYNAMIC_ARRAY_HPP_