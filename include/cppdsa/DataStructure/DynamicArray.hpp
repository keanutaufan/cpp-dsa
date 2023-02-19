#include <cstddef>
#include <stdexcept>
#include <type_traits>
#include <utility>

namespace DSA
{

template <typename DynamicArray>
class DynamicArrayIterator
{
public:
    using ValueType         = typename DynamicArray::ValueType;
    using SizeType          = std::size_t;
    using Reference         = ValueType&;
    using ConstReference    = const ValueType&;
    using Pointer           = ValueType*;
    using ConstPointer      = const ValueType*;

public:
    DynamicArrayIterator(Pointer pointer)
        : m_pointer(pointer)
    {}

    DynamicArrayIterator& operator++()
    {
        ++m_pointer;
        return *this;
    }

    DynamicArrayIterator operator++(int)
    {
        DynamicArrayIterator temp = *this;
        ++(*this);
        return temp;
    }

    DynamicArrayIterator& operator--()
    {
        --m_pointer;
        return *this;
    }

    DynamicArrayIterator operator--(int)
    {
        DynamicArrayIterator temp = *this;
        --(*this);
        return temp;
    }

    Reference operator[](SizeType index) noexcept
    {
        return m_pointer[index];
    }

    ConstReference operator[](SizeType index) const noexcept
    {
        return m_pointer[index];
    }

    Pointer operator->() noexcept
    {
        return m_pointer;
    }

    ConstPointer operator->() const noexcept
    {
        return m_pointer;
    }

    Reference operator*() noexcept
    {
        return *m_pointer;
    }

    ConstReference operator*() const noexcept
    {
        return *m_pointer;
    }

    constexpr bool operator==(const DynamicArrayIterator& other) const noexcept
    {
        return m_pointer == other.m_pointer;
    }

    constexpr bool operator!=(const DynamicArrayIterator& other) const noexcept
    {
        return !(m_pointer == other.m_pointer);
    }

private:
    Pointer m_pointer = nullptr;
};

template <typename T>
class DynamicArray
{
public:
    using ValueType         = T;
    using SizeType          = std::size_t;
    using Reference         = ValueType&;
    using ConstReference    = const ValueType&;
    using RvalueReference   = ValueType&&;
    using Pointer           = ValueType*;
    using ConstPointer      = const ValueType;
    using Iterator          = DynamicArrayIterator<DynamicArray<ValueType>>;

public:
    DynamicArray()
        : m_size(0), m_capacity(INIT_CAPACITY)
    {
        m_buffer = static_cast<Pointer>(operator new(INIT_CAPACITY * sizeof(ValueType)));
    }

    DynamicArray(SizeType count)
        : m_size(count), m_capacity(count)
    {
        m_buffer = new ValueType[count];
    }

    DynamicArray(SizeType count, ConstReference value)
        : m_size(count), m_capacity(count)
    {
        m_buffer = static_cast<Pointer>(operator new(count * sizeof(ValueType)));
        for (SizeType i = 0; i < count; i++) {
            new(&m_buffer[i]) ValueType(value);
        }
    }

    DynamicArray(const DynamicArray& other)
    {
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_buffer = static_cast<T*>(operator new(m_capacity * sizeof(ValueType)));

        for (SizeType i = 0; i < m_size; i++) {
            new(&m_buffer[i]) ValueType(other.m_buffer[i]);
        }
    }

    DynamicArray(DynamicArray&& other)
    {
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_buffer = other.m_buffer;

        other.m_buffer = nullptr;
        other.m_size = 0;
        other.m_capacity = 0;
    }

    ~DynamicArray()
    {
        Clear();
        m_capacity = 0;
    }

    DynamicArray& operator=(const DynamicArray& other)
    {
        if (this != &other) {
            Clear();

            m_size = other.m_size;
            m_capacity = other.m_capacity;
            m_buffer = static_cast<Pointer>(operator new(m_capacity * sizeof(ValueType)));

            for (SizeType i = 0; i < m_size; i++) {
                new(&m_buffer[i]) ValueType(other.m_buffer[i]);
            }
        }

        return *this;
    }

    DynamicArray& operator=(DynamicArray&& other)
    {
        if (this != &other)
        {
            Clear();

            m_size = other.m_size;
            m_capacity = other.m_capacity;
            m_buffer = other.m_buffer;

            other.m_buffer = nullptr;
            other.m_size = 0;
            other.m_capacity;
        }

        return *this;
    }

    Reference At(SizeType index)
    {
        if (index >= m_size) {
            throw std::out_of_range("Index out of range.");
        }

        return m_buffer[index];
    }

    ConstReference At(SizeType index) const
    {
        if (index >= m_size) {
            throw std::out_of_range("Index out of range.");
        }

        return m_buffer[index];
    }

    Reference operator[](SizeType index)
    {        
        return m_buffer[index];
    }

    ConstReference operator[](SizeType index) const
    {
        return m_buffer[index];
    }

    Reference Front()
    {
        if (m_size == 0) {
            throw std::out_of_range("Array is empty.");
        }

        return m_buffer[0];
    }

    ConstReference Front() const
    {
        if (m_size == 0) {
            throw std::out_of_range("Array is empty");
        }

        return m_buffer[0];
    }

    Reference Back()
    {
        if (m_size == 0) {
            throw std::out_of_range("Array is empty.");
        }

        return m_buffer[m_size-1];
    }

    ConstReference Back() const
    {
        if (m_size == 0) {
            throw std::out_of_range("Array is empty.");
        }

        return m_buffer[m_size-1];
    }

    Pointer Data() noexcept
    {
        return m_buffer;
    }

    constexpr ConstPointer Data() const noexcept
    {
        return m_buffer;
    }

    Iterator begin()
    {
        return Iterator(m_buffer);
    }

    Iterator end()
    {
        return Iterator(m_buffer + m_size);
    }

    constexpr bool IsEmpty() const noexcept
    {
        return m_size == 0;
    }

    constexpr SizeType Size() const noexcept
    {
        return m_size;
    }

    constexpr SizeType Capacity() const noexcept
    {
        return m_capacity;
    }

    void Reserve(SizeType newCapacity)
    {
        if (newCapacity > m_capacity) {
            Reallocate(newCapacity);
        }
    }

    void ShrinkToFit()
    {
        Reallocate(m_size);
    }

    void Clear()
    {
        if (IS_CLASS) {
            for (SizeType i = 0; i < m_size; i++) {
                m_buffer[i].~ValueType();
            }
        }

        operator delete(m_buffer, m_capacity * sizeof(ValueType));
        m_size = 0;
    }

    void PushBack(ConstReference value)
    {
        if (m_capacity <= m_size) {
            Reallocate(static_cast<SizeType>(m_capacity * GROWTH_FACTOR));
        }

        new(&m_buffer[m_size++]) ValueType(value);
    }

    void PushBack(RvalueReference value)
    {
        if (m_capacity <= m_size) {
            Reallocate(static_cast<SizeType>(m_capacity * GROWTH_FACTOR));
        }

        new (&m_buffer[m_size++]) ValueType(std::move(value));
    }

    template <typename... Args>
    void EmplaceBack(Args&&... args)
    {
        if (m_capacity <= m_size) {
            Reallocate(static_cast<SizeType>(m_capacity * GROWTH_FACTOR));
        }

        new(&m_buffer[m_size++]) ValueType(std::forward<Args>(args)...);
    }

    void PopBack() {
        if (m_size == 0) {
            throw std::underflow_error("Array is empty.");
        }

        if (IS_CLASS) {
            m_buffer[m_size-1].~ValueType();
        }

        m_size--;
    }

private:
    SizeType m_size = 0;
    SizeType m_capacity = 0;
    Pointer m_buffer = nullptr;

private:
    static constexpr SizeType INIT_CAPACITY = 2;
    static constexpr double GROWTH_FACTOR = 2.0;
    static constexpr bool IS_CLASS = std::is_class<T>::value;

private:
    void Reallocate(SizeType newCapacity)
    {
        Pointer newBuffer = static_cast<Pointer>(operator new(newCapacity * sizeof(ValueType)));

        if (newCapacity < m_size) {
            for (SizeType i = newCapacity; i < m_size; i++) {
                m_buffer[i].~ValueType();
            }

            m_size = newCapacity;
        }

        for (SizeType i = 0; i < m_size; i++) {
            new (&newBuffer[i]) ValueType(std::move(m_buffer[i]));
        }

        for (SizeType i = 0; i < m_size; i++) {
            m_buffer[i].~ValueType();
        }

        operator delete(m_buffer, m_capacity * sizeof(ValueType));
        m_buffer = newBuffer;
        m_capacity = newCapacity;
    }
};

} // namespace DSA