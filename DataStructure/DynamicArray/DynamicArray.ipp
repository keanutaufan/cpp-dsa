#ifndef CPPDSA_DATA_STRUCTURE_DYNAMIC_ARRAY_IPP_
#define CPPDSA_DATA_STRUCTURE_DYNAMIC_ARRAY_IPP_

#include <cstddef>
#include <stdexcept>
#include "DynamicArray.hpp"

namespace DSA {
    template <typename T>
    void DynamicArray<T>::_resize(const std::size_t newCapacity) {
        T* newBuffer = new T[newCapacity];

        const std::size_t endPos = std::min(newCapacity, this->currentIndex);
        for (std::size_t i = 0; i < endPos; i++) {
            newBuffer[i] = buffer[i];
        }

        delete[] this->buffer;
        this->buffer = newBuffer;
        this->bufferCapacity = newCapacity;

        if (newCapacity < this->currentIndex) {
            this->currentIndex = newCapacity;
        }
    }

    template <typename T>
    void DynamicArray<T>::_shift_right(const std::size_t startPos, const std::size_t count) {
        std::size_t minimumRequiredCapacity = this->currentIndex + count;
        if (minimumRequiredCapacity > this->bufferCapacity) {
            std::size_t newCapacity = this->bufferCapacity;
            while (newCapacity < minimumRequiredCapacity) {
                newCapacity *= _DYNAMIC_ARRAY_GROWTH_FACTOR;
            }
            this->_resize(newCapacity);
        }

        for (std::size_t i = minimumRequiredCapacity-1; i >= startPos+count; i--) {
            buffer[i] = buffer[i-count];
        }

        this->currentIndex += count;
    }

    template <typename T>
    void DynamicArray<T>::_shift_left(const std::size_t startPos, const std::size_t count) {
        for (std::size_t i = startPos; i < currentIndex-count; i++) {
            buffer[i] = buffer[i+count];
        }

        this->currentIndex -= count;
    }

    template <typename T>
    DynamicArray<T>::DynamicArray() {
        this->buffer = new T[_DYNAMIC_ARRAY_INIT_SIZE];
        this->currentIndex = 0;
        this->bufferCapacity = _DYNAMIC_ARRAY_INIT_SIZE;
    }

    template <typename T>
    void DynamicArray<T>::push_back(const T& value) {
        if (this->currentIndex >= this->bufferCapacity) {
            this->_resize(this->bufferCapacity * _DYNAMIC_ARRAY_GROWTH_FACTOR);
        }

        this->buffer[currentIndex++] = value;
    }

    template <typename T>
    void DynamicArray<T>::pop_back() {
        if (this->isEmpty()) {
            throw std::underflow_error("Array is empty.");
        }

        this->currentIndex--;
    }

    template <typename T>
    void DynamicArray<T>::insert_at(const std::size_t index, const T& value) {
        if (index < 0 || index >= this->currentIndex) {
            throw std::out_of_range("Index out of range.");
        }

        this->_shift_right(index, 1);
        this->buffer[index] = value;
    }

    template <typename T>
    void DynamicArray<T>::insert_at(const std::size_t index, const T& value, const std::size_t count) {
        if (index < 0 || index >= this->currentIndex) {
            throw std::out_of_range("Index out of range.");
        }

        this->_shift_right(index, count);
        for (std::size_t i = index; i < index+count; i++) {
            this->buffer[i] = value;
        }
    }

    template <typename T>
    void DynamicArray<T>::remove_at(const std::size_t index) {
        if (this->isEmpty()) {
            throw std::underflow_error("Array is empty.");
        }

        this->_shift_left(index, 1);
    }

    template <typename T>
    void DynamicArray<T>::remove_at(const std::size_t index, const std::size_t count) {
        if (index + count > this->currentIndex) {
            throw std::out_of_range("End removal position is out of range.");
        }

        this->_shift_left(index, count);
    }

    template <typename T>
    void DynamicArray<T>::resize(const std::size_t count) {
        std::size_t previousIndex = this->currentIndex;
        this->_resize(count);
        if (previousIndex < count) {
            for (std::size_t i = previousIndex; i < count; i++) {
                this->buffer[i] = T();
            }
        }
        this->currentIndex = count;
    }

    template <typename T>
    void DynamicArray<T>::resize(const std::size_t count, const T& value) {
        std::size_t previousIndex = this->currentIndex;
        this->_resize(count);
        if (previousIndex < count) {
            for (std::size_t i = previousIndex; i < count; i++) {
                this->buffer[i] = value;
            }
        }
        this->currentIndex = count;
    }

    template <typename T>
    inline bool DynamicArray<T>::isEmpty() const {
        return this->currentIndex == 0;
    }

    template <typename T>
    inline std::size_t DynamicArray<T>::size() const {
        return this->currentIndex;
    }

    template <typename T>
    inline std::size_t DynamicArray<T>::capacity() const {
        return this->bufferCapacity;
    }

    template <typename T>
    void DynamicArray<T>::reserve(const std::size_t newCapacity) {
        if (newCapacity > this->bufferCapacity) {
            this->_resize(newCapacity);
        }
    }

    template <typename T>
    void DynamicArray<T>::clear() {
        delete[] this->buffer;
        this->buffer = new T[_DYNAMIC_ARRAY_INIT_SIZE];
        this->currentIndex = 0;
    }

    template <typename T>
    void DynamicArray<T>::shrink_to_fit() {
        this->_resize(this->currentIndex);
    }

    template <typename T>
    T& DynamicArray<T>::front() {
        if (this->isEmpty()) {
            throw std::out_of_range("Array is empty.");
        }

        return this->buffer[0];
    }

    template <typename T>
    T& DynamicArray<T>::back() {
        if (this->isEmpty()) {
            throw std::out_of_range("Array is empty");
        }

        return this->buffer[this->currentIndex-1];
    }

    template <typename T>
    T& DynamicArray<T>::at(const std::size_t index) {
        if (index < 0 || index >= this->currentIndex) {
            throw std::out_of_range("Index out of range.");
        }

        return this->buffer[index];
    }

    template <typename T>
    inline T& DynamicArray<T>::operator[](const std::size_t index) {
        return this->buffer[index];
    }

    template <typename T>
    inline T* DynamicArray<T>::data() {
        return this->buffer;
    }

    template <typename T>
    DynamicArray<T>::~DynamicArray() {
        delete[] this->buffer;
    }
}

#endif // CPPDSA_DATA_STRUCTURE_DYNAMIC_ARRAY_IPP_
