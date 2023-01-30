# C++ Data Structures and Algorithms

Implementation of various popular data structures and algorithms in C++
with clear explanations.

## What is this?

This repository contains popular data structures and algorithms
(mostly simple stuff) implemented in C++ with its explanations.
I will try to document and explain the code as clearly as possible,
so more people can learn from my journey.

## Contents

### Data Structures

- [Dynamic Array](DataStructure/DynamicArray)
- [Stack](DataStructure/Stack)
- [Queue](DataStructure/Queue)
- [Deque](DataStructure/Deque)
- [Linked List](DataStructure/LinkedList)
- [Binary Search Tree (with fair explanation about binary tree)](DataStructure/BinarySearchTree)

more to come...

## A Note on Complexity and Performance

I provide the time complexity for each algorithm and data structure operation
in the documentation. However, please note that the time complexity may not
necessary reflect the actual performance of the algorithm or method.
This is because the time complexity is usually measured in terms of the number
of operations, which is not necessarily the same as the number of CPU cycles
or clock cycles. For example, the time complexity of a simple `for` loop is
$O(n)$, but the actual performance of the loop may be much better than that.
The reason is that the compiler may optimize the loop to use SIMD instructions
or other techniques to speed up the loop. In fact, the performance of the
loop may be very fast if the compiler is smart enough to optimize it.

The time complexity merely measures how the algorithm or method scales with the
number of data processed. In other word, it measures the growth rate of the
computing time as the input size grows. If the operations performed by the
algorithm itself is slow, even a $O(1)$ algorithm may take longer to run than a
$O(n)$ algorithm. In academic settings, the time complexity is usually measured
in terms of the number of operations, but in real-world applications, the
actual performance is usually more important.

A code which generates a random number may have a time complexity of $O(1)$,
but the actual performance may slow. The reason is that generating a random
number is not a simple operation. It involves a lot of computation, and the
actual performance may be much worse than what you expect. Both `idiv` and
`imul` instructions are $O(1)$, but `idiv` is generally way more expensive
and requires more clock cycles than `imul`. If an algorithm involves, say, a
million `idiv` instructions, it may take longer to run than an algorithm that
involves a million `imul` instructions, despite them having the same number
of operations. 

The same thing applies to the data structures. A hash table may promise $O(1)$
time complexity amortized for insertion, but the hash table needs to perform
hashing and collision resolution, which is very expensive. In some cases,
the hash table may be slower than, for example, a balanced binary search tree,
despite the hash table having a better time complexity.

Another thing to consider when implementing a data structure is the
locality of reference. Many modern machines nowadays have a large cache.
Cache misses are very expensive, so the locality of reference has
become much more important than before. In context of data structures,
a node-based data structure has a very poor locality of reference. This 
makes it much slower than an array-based data structure, even if the
array-based data structure has a worse time complexity in certain cases.

Cache considerations are not usually taken into account when measuring
the time complexity of an algorithm or data structure, though it can
help us make better decisions when choosing an algorithm or data structure
for a particular application. Cache considerations can also mean that
it may not be a good idea to use a linked list over `std::vector`, even
for some situations where the time complexity of the linked list is
better than that of the vector like insertion in the middle of the list,
like many textbooks would suggest.

In a language like C++, this can get even more complicated. The compiler
may optimize the code to produce better performance, so you may need
to understand how the compiler works to get a better understanding of
the actual performance of the code. For example, passing around a large
object by reference even when we don't need to modify the object is often
suggested by many sources as it does not involve copying the object,
but under certain optimization levels, some compilers may actually perform
better if we pass the object by value by generating some assembly instructions
to optimize the object passing. On the other hand, passing an object
by reference closes the possibility of the compiler to perform some
optimizations, because it may assume that the data in the reference
may be modified anywhere in the program. 

There are also important considerations about when do we use specific
features of the language. For example, we may want to use `std::move`
to invoke the move constructor of an object, but in some cases maybe
it is better to avoid using `std::move` and use `std::copy` instead.
C++ has so many features that does seemingly the same thing, but
works really differently on low level. 

Hardware also plays a big role in the performance of the code. For example,
a tensor core in a modern GPU can perform matrix multiplication much
faster than a CPU, but that's just how the hardware is designed. A
GPU can also perform a lot of floating point operations in parallel,
so it can be much faster than a CPU for some tasks. A good programmer
knows when to pass certain computations to certain hardware, effectively
using the hardware to its full potential.

But this is just a small part of the story. We may also need to consider
operating system, multi-threading capability, and other factors. I might
mention some of these things in some explanations of the algorithms and
data structures, but I will not go into too much details. My goal is to
provide a reference of how certain algorithms and data structures work,
how they can be implemented in C++, and what are their theoretical
time complexities. I want to keep the explanations as brief as possible,
and I don't really want to bloat the repository with information that
is not directly related to the algorithms and data structures.

Ah, where were we? Oh yes, the time complexity. While I have just mentioned
that the time complexity is not necessarily the same as the actual performance,
it is still a good measure of how the algorithm or data structure scales
and should never be ignored. Also, while this probably mean that a handmade
algorithm or data structure rarely beats a well-designed algorithm or data
structure from a well-maintained library, it does not mean that we should
give up the notion of writing our own algorithms and data structures altogether.
You see, understanding how things work under the hood will make you
able to make better decisions when dealing with real-world applications.

Anyway, I hope this paragraph will help you understand a little bit
more about the time complexity and how it relates to the actual performance.

## Important Notice

The implementations of hosted algorithms and data structures are not
necessarily the most efficient, nor are they guaranteed to be bug-free.
After all, this repository is intended to serve as a reference and learning
resource rather than a production-ready library for large-scale applications.
If you are planning to do something serious, I recommend using C++
STL or a well-maintained library like [Boost](https://github.com/boostorg/boost). 
Should you wish to use this code, please do so at your own risk.

## Dev Notes

My intention with this repository is mainly to provide a reference
for students and programmers who are interested in learning about
algorithms and data structures about how they work in theory and
the general idea of how they can be implemented in C++. That being said,
the first thing that came to my mind when I started this project was
to use "C with Classes" approach instead a proper, more modern C++
actually used in real-world applications nowadays. I'm aware that
this may not be the best approach of doing things in C++ especially
in this day and age, but I think it is a good way to introduce
algorithms and data structures to those who mainly care about
the theory and the general idea of how they work instead of
how they specifically work in C++, considering how confusing
they can be for those who are not yet familiar with it.

But now that I have started this project, I'm not sure if I should
continue using this approach or not. I can't really stand myself
labelling this project as "C++" when it is not really C++ at all.
You might have noticed that ownership management is done manually
instead of using smart pointers, and there are a lot of `new` and
`delete` statements. You might also have noticed that I'm not using
any advanced C++ features like move semantics, lambda expressions,
and so on. I also didn't take advantage of `constexpr` when I could.
The list goes on.

I'm not sure if I should continue using this approach or not. Yes,
it may be a non-confusing way to introduce algorithms and data
structures to a lot of people, but on the other hand, I specifically
marked this project as a "C++ DSA Reference". I'm not really
sure how to proceed from here, so I'm open to suggestions.

## Contributing

Though it is not heavily targeted towards real-world applications, I'd like
to make the collection of these algorithms and data structures as efficient
and safe as possible, to the point that this project is good
enough to be used for production. So if you find any bug or inefficiency,
please open an issue or send a pull request. That being said, my intention
is to prioritize readability and simplicity over efficiency, so if me
not using some advanced C++ features or techniques is the reason why
the code is not efficient, I may not consider to change it.

You can also contribute to non-code parts of this repository. After all,
this is a learning resource, and I'd like to make it as clear and
understandable as possible. Here are some ways you can help:

- Spot and fix typos and grammatical errors. I'm not a native English
  speaker, so any wordsmithing is appreciated.
- Report any broken links. I may have missed some links when I was
  moving files around, or I may have deleted some files that are still
  linked to. There are also some external links in the references that may
  be broken. However, there may be some links pointing to some data structures
  or algorithms that are not yet implemented, in which case I intentionally
  left them as I am planning to implement them in the future.
- Correct any misleading or incorrect explanations. If you spot any
  of these, please let me know before it misleads other readers.
- Improve the explanations! We need feedback from you as the reader to
  make this resource better. Did you find something confusing? Did you
  find something that could be explained better? Did you find any
  explanation that was awkwardly phrased? Let me know!
- Add or revise graphs and diagrams. I'm not a designer, so if you have
  any ideas on how to make the them better, please let me know.
- Eventually, I'd like to replace some of the graphics with animations to make
  the explanations more intuitive once I have the time to do so. My goal is to
  have them in every algorithm and data structure operations that needs them.
  If you are interested in helping me with this, please contact me.

Currently, I'm not accepting pull requests for new algorithms and data
structures until I define a proper contribution guideline (i.e. style guide).
However, I'm open to suggestions for new algorithms and data structures to add.

## License
[MIT](LICENSE)