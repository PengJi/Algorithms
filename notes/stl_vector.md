# 变长数组，倍增的思想

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

妙用
```cpp
vector<int> vec[26];  // 相当于二维数组，有 26个元素，每个元素是一个 vector
vec.push_back(1);  // 第一个 vector 插入一个元素
```