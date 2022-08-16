# C++ STL
The Standard Template Library (STL) is a set of C++ template classes to provide common programming data structures and functions such as lists, stacks, arrays, etc. It is a library of container classes, algorithms, and iterators. It is a generalized library and so, its components are parameterized.

# Containers
## Sequence Containers: implement data structures which can be accessed in a sequential manner.

* vector
变长数组，倍增的思想  
```cpp
size()  // 返回元素个数
empty()  // 返回是否为空
clear()  // 清空
front()/back()
push_back()/pop_back()
begin()/end()
insert(v.begin(), 0)  // 队首插入 0
[]
支持比较运算，按字典序
```

* list

* deque
双端队列
```cpp
size()
empty()
clear()
front()/back()
push_back()/pop_back()
push_front()/pop_front()
begin()/end()
[]
```

* arrays

* forward_list( Introduced in C++11)


## Container Adaptors : provide a different interface for sequential containers.

* queue
```cpp
size()
empty()
push()  // 向队尾插入一个元素
pop()  // 弹出队头元素
front()  // 返回队头元素
back()  // 返回队尾元素
```

* priority_queue  
优先队列，默认是大根堆
```cpp
size()
empty()
push()  // 插入一个元素
pop()  // 弹出堆顶元素
top()  // 返回堆顶元素
定义成小根堆的方式：priority_queue<int, vector<int>, greater<int>> q;
```

* stack
```cpp
size()
empty()
push()  // 向栈顶插入一个元素
pop()  // 弹出栈顶元素
top()  // 返回栈顶元素
```

## Associative Containers : implement sorted data structures that can be quickly searched (O(log n) complexity).
* set
* multiset
* map
* multimap

`set/multiset/map/multimap`
基于平衡二叉树（红黑树），动态维护有序序列，操作：
```cpp
size()
empty()
clear()
begin()/end()
++, -- // 返回前驱和后继，时间复杂度 O(logn)
```

`set/multiset`
```cpp
insert()  // 插入一个数
find()  // 查找一个数
count()  // 返回某一个数的个数
erase()
(1) 输入是一个数x，删除所有x   O(k + logn)
(2) 输入一个迭代器，删除这个迭代器
lower_bound()/upper_bound()
lower_bound(x)  //返回大于等于x的最小的数的迭代器
upper_bound(x)  // 返回大于x的最小的数的迭代器
```

`map/multimap`
```cpp
insert()  // 插入的数是一个pair
erase()  // 输入的参数是pair或者迭代器
find()
[]  注意multimap不支持此操作。 时间复杂度是 O(logn)
lower_bound()/upper_bound()
```

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


# others
`string`
```cpp
size()/length()  // 返回字符串长度
empty()
clear()
substr(起始下标，(子串长度))  // 返回子串
c_str()  // 返回字符串所在字符数组的起始地址
```

`pair<int, int>`  
```cpp
first  // 第一个元素
second  // 第二个元素
支持比较运算，以first为第一关键字，以second为第二关键字（字典序）
```

`hash`
```
哈希表，和上面类似，增删改查的时间复杂度是 O(1)。  
不支持 lower_bound()/upper_bound()， 迭代器的++，--
```

`bitset` 
圧位
```cpp
bitset<10000> s;
~, &, |, ^
>>, <<
==, !=
[]

count()  // 返回有多少个1
any()  // 判断是否至少有一个1
none()  // 判断是否全为0

set()  // 把所有位置成1
set(k, v)  // 将第k位变成v
reset()  //把所有位变成0
flip()  // 等价于~
flip(k)  //把第k位取反
```
