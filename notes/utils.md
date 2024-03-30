```cpp
// mod 2 的余数
if (num % 2 == 0)
// 等同于
if (num & 2)

// 2 的 n 次方：2^n
1 << n

// 任何数的 n 次方：x^n
x << n
```


初始化动态数组
```cpp
int len = s.size();
bool* pos = new bool[len];
delete[] pos;
```

vector 高效的插入
```cpp
vec.emplace_back(1);

// 插入 pair
vector<pair<int, string>> vec;
vec.emplace_back(1, "abc");
```
