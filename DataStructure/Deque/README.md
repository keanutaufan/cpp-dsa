# Deque

## Introduction

A deque (pronounced "deck") is a double-ended queue. Unlike a traditional
[queue](../Queue/), where elements can only be inserted at the back and removed
from the front, a deque allows for elements to be added or removed from either end.
This means that it has the properties of both a [queue](../Queue/) and a 
[stack](../Stack/), allowing for efficient insertion and removal of elements
from both ends.

<div align="center">
    <img src="img/narrow-queue.png" alt="Deque" width="450" height="300">
</div>

You can think a deque as a group of people queuing up to get on a roller coaster.
Like how a queue works, the first person in line is the first one to get on the
roller coaster. However, this time, the last person in line can decide whether
they want to get on the roller coaster or not. If they decide not to get on the
roller coaster, they can choose to leave the line and not get on the roller coaster.
This is the same as removing an element from the back of the deque. If they decide
to get on the roller coaster, they will be the last one to get on the roller
coaster. This is the same as adding an element to the back of the deque. The
limitation of this analogy is that only the last person in line can decide whether
they want to leave the line early or not. You might imagine that the queue is
so narrow that the person in the middle of the line cannot leave the line early
without affecting the people behind them.

## Operations

A deque data structure supports at least these basic operations:

- `push_front` or `shift` - Adds an element to the front of the deque.
- `push_back` or `push` - Adds an element to the back of the deque.
- `pop_front` or `unshift` - Removes the element at the front of the deque.
- `pop_back` or `pop` - Removes the element at the back of the deque.
- `front` - Returns the element at the front of the deque.
- `back` - Returns the element at the back of the deque.
- `isEmpty` - Returns true if the deque is empty, false otherwise.

Some implementation of a deque may also keep track of the size of the deque,
which would allow the user to query the size of the deque. This implementation
would also support the `size` operation, which returns the size of the deque.

## Time Complexity

|   Operation  | Time Complexity |
|:------------:|:---------------:|
| `push_front` | $O(1)$          |
| `push_back`  | $O(1)$          |
| `pop_front`  | $O(1)$          |
| `pop_back`   | $O(1)$          |
| `front`      | $O(1)$          |
| `back`       | $O(1)$          |
| `isEmpty`    | $O(1)$          |
| `size`       | $O(1)$          |

As you can see, all of the operations on a deque are in constant time, which
is a very efficient time complexity. This is because the deque only needs to
access either the front or the back of the queue at any given time. This means
that the deque does not need to traverse the entire elements to perform any of
the operations, making it very efficient.

## Implementation

The implementation of a deque is very similar to the implementation of a
[queue](../Queue/). The only difference is that the deque allows for elements
to be added and removed from either end. A deque can be implemented using an array,
with fixed size, a dynamic array, a linked list, or a combination of them.

When implemented using an array, the array is treated as a circular buffer, where
elements are added or removed from the front or back by adjusting the front and back
indices. This allows for constant-time insertion and removal of elements, but can
result in wasted space if the deque is not full.

<div align="center">
    <img src="img/deque-array.svg" alt="Array" width="300" height="300">
</div>

When implemented using a linked list, the deque is typically thought of as a doubly
linked list, where each node has links to both the next and previous nodes.
A wrapper class is used to keep track of the front and back of the deque. This
allows for dynamic allocation of memory, but some extra memory is used to store
the links to the next and previous nodes. This will make the deque less efficient
when used with small data types.

<div align="center">
    <img src="img/deque-linked-list.svg" alt="Linked List" width="400" height="300">
</div>

The deque will be implemented as a template class, which means that the deque
can store elements of any type. Because C++ template classes and methods can not
be implemented in separate `.cpp` files, the implementation of the deque will
either be in the header file itself or separate implementation file that will be
included in the header file. This repository will use the latter approach, using
an `.ipp` file as the implementation file.

### Node

Because the deque will be implemented using a doubly linked list, the deque will
need some kind of node with link to store the data and link to the next and 
previous node so that element deletion can be performed from both ends of the deque.
The node will be implemented as a template struct, which will allow the user to
use the deque with any data type. The node itself will be defined as a private
member within the deque class to prevent the user from accessing the node directly.

```cpp
template <typename T>
struct DequeContainer {
    T data;
    DequeContainer<T>* next;
    DequeContainer<T>* prev;
};
```

### Class Definition

The deque class will be defined as a template class, which means that the user
can use the deque with any data type. The class will have the following private
members:

- `head` - A pointer to the front of the deque.
- `tail` - A pointer to the back of the deque.
- `dequeSize` - The size of the deque.

The class will have the following public methods:
- `Deque` - The constructor for the deque.
- `push_front` - Adds an element to the front of the deque.
- `push_back` - Adds an element to the back of the deque.
- `pop_front` - Removes the element at the front of the deque.
- `pop_back` - Removes the element at the back of the deque.
- `peek_front` - Returns the element at the front of the deque.
- `peek_back` - Returns the element at the back of the deque.
- `isEmpty` - Returns true if the deque is empty, false otherwise.
- `size` - Returns the size of the deque.
- `~Deque` - The destructor for the deque.

```cpp
template <typename T>
class Deque {
private:
    template <typename U>
    struct DequeContainer {
        U data;
        DequeContainer<U>* next;
        DequeContainer<U>* prev;
    };

    DequeContainer<T>* head;
    DequeContainer<T>* tail;
    std::size_t dequeSize;

public:
    Deque();

    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();

    const T& peek_front();
    const T& peek_back();

    bool isEmpty();
    std::size_t size();

    ~Deque();
};
```

### Constructor

The constructor for the deque will initialize the `head` and `tail` pointers to
`nullptr` and the `dequeSize` to `0`.

```cpp
template <typename T>
Deque<T>::Deque() {
    this->head = nullptr;
    this->tail = nullptr;
    this->dequeSize = 0;
}
```

### `push_front`

The `push_front` method will add an element to the front of the deque. The method
will take in a constant reference to the element to be added. The method will
create a new node to store the element and add it to the front of the deque. If
the deque is empty, the `head` and `tail` pointers will be set to the new node.
Otherwise, the `head` pointer will be updated to point to the new node. The
`dequeSize` will be incremented by 1.

```cpp
template <typename T>
void Deque<T>::push_front(const T& value) {
    DequeContainer<T>* newElement = new DequeContainer<T>();
    newElement->data = value;
    newElement->next = nullptr;
    newElement->prev = nullptr;

    if (this->isEmpty()) {
        this->head = newElement;
        this->tail = newElement;
    }
    else {
        newElement->next = this->head;
        this->head->prev = newElement;
        this->head = newElement;
    }

    this->dequeSize++;
}
```

### `push_back`

The `push_back` method will add an element to the back of the deque. The method
will take in a constant reference to the element to be added. The method will
create a new node to store the element and add it to the back of the deque. If
the deque is empty, the `head` and `tail` pointers will be set to the new node.
Otherwise, the `tail` pointer will be updated to point to the new node. The
`dequeSize` will be incremented by 1.

```cpp
template <typename T>
void Deque<T>::push_back(const T& value) {
    DequeContainer<T>* newElement = new DequeContainer<T>();
    newElement->data = value;
    newElement->next = nullptr;
    newElement->prev = nullptr;

    if (this->isEmpty()) {
        this->head = newElement;
        this->tail = newElement;
    }
    else {
        newElement->prev = this->tail;
        this->tail->next = newElement;
        this->tail = newElement;
    }

    this->dequeSize++;
}
```

### `pop_front`

The `pop_front` method will remove the element at the front of the deque. The
method will check if the deque is empty. If the deque is empty, the method will
throw an `std::underflow_error` exception. If the deque has exactly one element,
the `head` and `tail` pointers will be set to `nullptr` after deletion. Otherwise,
the `head` pointer will be updated to point to the next node in the deque. The `dequeSize` will be decremented by 1.

```cpp
template <typename T>
void Deque<T>::pop_front() {
    if (this->dequeSize == 0) {
        throw std::underflow_error("Deque is empty.");
    }
    else if (this->dequeSize == 1) {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
    }
    else {
        DequeContainer<T>* newHead = this->head->next;
        newHead->prev = nullptr;
        delete this->head;
        this->head = newHead;
    }

    this->dequeSize--;
}
```

### `pop_back`

The `pop_back` method will remove the element at the back of the deque. The
method will check if the deque is empty. If the deque is empty, the method will
throw an `std::underflow_error` exception. If the deque has exactly one element,
the `head` and `tail` pointers will be set to `nullptr` after deletion. Otherwise,
the `tail` pointer will be updated to point to the previous node in the deque.
The `dequeSize` will be decremented by 1.

```cpp
template <typename T>
void Deque<T>::pop_back() {
    if (this->dequeSize == 0) {
        throw std::underflow_error("Deque is empty.");
    }
    else if (this->dequeSize == 1) {
        delete this->tail;
        this->head = nullptr;
        this->tail = nullptr;
    }
    else {
        DequeContainer<T>* newTail = this->tail->prev;
        newTail->next = nullptr;
        delete this->tail;
        this->tail = newTail;
    }

    this->dequeSize--;
}
```

### `peek_front`

The `peek_front` method will return the element at the front of the deque. 
The method will be an inline method that will return the `data` member of the
`head` node.

```cpp
template <typename T>
inline const T& Deque<T>::peek_front() {
    return this->head->data;
}
```

### `peek_back`

The `peek_back` method will return the element at the back of the deque.
The method will be an inline method that will return the `data` member of the
`tail` node.

```cpp
template <typename T>
inline const T& Deque<T>::peek_back() {
    return this->tail->data;
}
```

### `isEmpty`

The `isEmpty` method will return a boolean value indicating if the deque is
empty. The method will be an inline method that will return `true` if the
`dequeSize` is `0` and `false` otherwise.

```cpp
template <typename T>
inline bool Deque<T>::isEmpty() {
    return this->dequeSize == 0;
}
```

### `size`

The `size` method will return the size of the deque. The method will be an
inline method that will return the `dequeSize` member.

```cpp
template <typename T>
inline std::size_t Deque<T>::size() {
    return this->dequeSize;
}
```

### Destructor

The destructor will be responsible for deleting all of the nodes in the deque.
While the deque instance itself will be deleted by the compiler assuming it
is allocated on the stack, the nodes will need to be deleted manually as it is
stored on the heap and the user has no way of accessing the nodes as it is
private to the class. The destructor will iterate through the deque and delete
each node. 

```cpp
template <typename T>
Deque<T>::~Deque() {
    DequeContainer<T>* currentElement = this->head;
    while (currentElement != nullptr) {
        DequeContainer<T>* nextElement = currentElement->next;
        delete currentElement;
        currentElement = nextElement;
    }
}
```

## Testing

The deque class will not be tested using some kind of unit testing framework.
Instead, the deque class will be tested using a simple main function in a separate
`.cpp` file. The main function will perform some operations on the deque and
print the results to the console. The code for the main function can be found
in the `demo.cpp` file. Feel free to play around with the code and modify it
according to your needs.

## References

- [Deque - Wikipedia](https://en.wikipedia.org/wiki/Double-ended_queue)
- [Deque - C++ Reference](https://en.cppreference.com/w/cpp/container/deque)