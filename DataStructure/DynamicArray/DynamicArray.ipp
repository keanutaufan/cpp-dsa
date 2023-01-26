#ifndef CPPDSA_DATA_STRUCTURE_DYNAMIC_ARRAY_IPP_
#define CPPDSA_DATA_STRUCTURE_DYNAMIC_ARRAY_IPP_

#include <cstddef>
#include <stdexcept>
#include "DynamicArray.hpp"

namespace DSA {
    template <typename T>
    void DynamicArray<T>::_resize(const std::size_t newCapacity) {
        T* newBuffer = new T[newCapacity];

        const std::size_t endPos = std::min(newCapacity, m_size);
        for (std::size_t i = 0; i < endPos; i++) {
            newBuffer[i] = m_buffer[i];
        }

        delete[] m_buffer;
        m_buffer = newBuffer;
        m_capacity = newCapacity;

        if (newCapacity < m_size) {
            m_size = newCapacity;
        }
    }

    template <typename T>
    void DynamicArray<T>::_shift_right(const std::size_t startPos, const std::size_t count) {
        std::size_t minimumRequiredCapacity = m_size + count;
        if (minimumRequiredCapacity > m_capacity) {
            std::size_t newCapacity = m_capacity;
            while (newCapacity < minimumRequiredCapacity) {
                newCapacity *= _DYNAMIC_ARRAY_GROWTH_FACTOR;
            }
            _resize(newCapacity);
        }

        for (std::size_t i = minimumRequiredCapacity-1; i >= startPos+count; i--) {
            m_buffer[i] = m_buffer[i-count];
        }

        m_size += count;
    }

    template <typename T>
    void DynamicArray<T>::_shift_left(const std::size_t startPos, const std::size_t count) {
        for (std::size_t i = startPos; i < m_size-count; i++) {
            if (!_IS_TYPE_POINTER) {
                m_buffer[i].~T();
            }            
            m_buffer[i] = m_buffer[i+count];
        }

        m_size -= count;
    }

    template <typename T>
    DynamicArray<T>::DynamicArray() {
        m_buffer = new T[_DYNAMIC_ARRAY_INIT_SIZE];
        m_size = 0;
        m_capacity = _DYNAMIC_ARRAY_INIT_SIZE;
    }

    template <typename T>
    void DynamicArray<T>::push_back(const T& value) {
        if (m_size >= m_capacity) {
            _resize(m_capacity * _DYNAMIC_ARRAY_GROWTH_FACTOR);
        }

        m_buffer[m_size++] = value;
    }

    template <typename T>
    void DynamicArray<T>::pop_back() {
        if (is_empty()) {
            throw std::underflow_error("Array is empty.");
        }

        if (!_IS_TYPE_POINTER) {
            m_buffer[m_size-1].~T();
        }

        m_size--;
    }

    template <typename T>
    void DynamicArray<T>::insert_at(const std::size_t index, const T& value) {
        if (index < 0 || index >= m_size) {
            throw std::out_of_range("Index out of range.");
        }

        _shift_right(index, 1);
        m_buffer[index] = value;
    }

    template <typename T>
    void DynamicArray<T>::insert_at(const std::size_t index, const T& value, const std::size_t count) {
        if (index < 0 || index >= m_size) {
            throw std::out_of_range("Index out of range.");
        }

        _shift_right(index, count);
        for (std::size_t i = index; i < index+count; i++) {
            m_buffer[i] = value;
        }
    }

    template <typename T>
    void DynamicArray<T>::remove_at(const std::size_t index) {
        if (is_empty()) {
            throw std::underflow_error("Array is empty.");
        }

        _shift_left(index, 1);
    }

    template <typename T>
    void DynamicArray<T>::remove_at(const std::size_t index, const std::size_t count) {
        if (index + count > m_size) {
            throw std::out_of_range("End removal position is out of range.");
        }

        _shift_left(index, count);
    }

    template <typename T>
    void DynamicArray<T>::resize(const std::size_t count) {
        std::size_t previousIndex = m_size;
        _resize(count);
        if (previousIndex < count) {
            for (std::size_t i = previousIndex; i < count; i++) {
                m_buffer[i] = T();
            }
        }
        m_size = count;
    }

    template <typename T>
    void DynamicArray<T>::resize(const std::size_t count, const T& value) {
        std::size_t previousIndex = m_size;
        _resize(count);
        if (previousIndex < count) {
            for (std::size_t i = previousIndex; i < count; i++) {
                m_buffer[i] = value;
            }
        }
        m_size = count;
    }

    template <typename T>
    inline bool DynamicArray<T>::is_empty() const {
        return m_size == 0;
    }

    template <typename T>
    inline std::size_t DynamicArray<T>::size() const {
        return m_size;
    }

    template <typename T>
    inline std::size_t DynamicArray<T>::capacity() const {
        return m_capacity;
    }

    template <typename T>
    void DynamicArray<T>::reserve(const std::size_t newCapacity) {
        if (newCapacity > m_capacity) {
            _resize(newCapacity);
        }
    }

    template <typename T>
    void DynamicArray<T>::clear() {
        delete[] m_buffer;
        m_buffer = new T[_DYNAMIC_ARRAY_INIT_SIZE];
        m_size = 0;
    }

    template <typename T>
    void DynamicArray<T>::shrink_to_fit() {
        _resize(m_size);
    }

    template <typename T>
    T& DynamicArray<T>::front() {
        if (is_empty()) {
            throw std::out_of_range("Array is empty.");
        }

        return m_buffer[0];
    }

    template <typename T>
    T& DynamicArray<T>::back() {
        if (is_empty()) {
            throw std::out_of_range("Array is empty");
        }

        return m_buffer[m_size-1];
    }

    template <typename T>
    T& DynamicArray<T>::at(const std::size_t index) {
        if (index < 0 || index >= m_size) {
            throw std::out_of_range("Index out of range.");
        }

        return m_buffer[index];
    }

    template <typename T>
    inline T& DynamicArray<T>::operator[](const std::size_t index) {
        return m_buffer[index];
    }

    template <typename T>
    inline T* DynamicArray<T>::data() {
        return m_buffer;
    }

    template <typename T>
    DynamicArray<T>::~DynamicArray() {
        delete[] m_buffer;
    }
}

#endif // CPPDSA_DATA_STRUCTURE_DYNAMIC_ARRAY_IPP_
