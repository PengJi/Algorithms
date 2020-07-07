# C++ STL
The Standard Template Library (STL) is a set of C++ template classes to provide common programming data structures and functions such as lists, stacks, arrays, etc. It is a library of container classes, algorithms, and iterators. It is a generalized library and so, its components are parameterized.

# Containers
## Sequence Containers: implement data structures which can be accessed in a sequential manner.
* vector
* list
* deque
* arrays
* forward_list( Introduced in C++11)

## Container Adaptors : provide a different interface for sequential containers.
* queue
* priority_queue
* stack

## Associative Containers : implement sorted data structures that can be quickly searched (O(log n) complexity).
* set
* multiset
* map
* multimap

## Unordered Associative Containers : implement unordered data structures that can be quickly searched
* unordered_set (Introduced in C++11)
* unordered_multiset (Introduced in C++11)
* unordered_map (Introduced in C++11)
* unordered_multimap (Introduced in C++11)

# Iterators
Iterators are used for working upon a sequence of values. They are the major feature that allow generality in STL.
* Iterators

# Algorithms
The header algorithm defines a collection of functions especially designed to be used on ranges of elements.They act on containers and provide means for various operations for the contents of the containers.
* Sorting
* Searching
* [Important STL Algorithms](https://www.geeksforgeeks.org/c-magicians-stl-algorithms/)
* [Useful Array algorithms](https://www.geeksforgeeks.org/useful-array-algorithms-in-c-stl/)
* [Partition Operations](https://www.geeksforgeeks.org/c-magicians-stl-algorithms/)

