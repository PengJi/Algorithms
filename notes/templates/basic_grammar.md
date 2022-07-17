# 数据范围
```c++
int8    [-128, 127]
int16   [-32768, 32767]
int32   [-2147483648, 2147483647]
int64   [-9223372036854775808, 9223372036854775807]

uint8   [0, 255]
uint16  [0, 65535]
uint32  [0, 4294967295]
uint64  [0, 18446744073709551615]
```

# 字符串
## [std::string::substr](https://www.cplusplus.com/reference/string/string/substr/)
## [std::string::find](http://www.cplusplus.com/reference/string/string/find/)
[删除字符串中的子串](https://leetcode-cn.com/problems/remove-all-occurrences-of-a-substring/)
```cpp
string removeOccurrences(string s, string p) {
    while(true) {
        int k = s.find(p);
        if(k == -1) break;
        s = s.substr(0, k) + s.substr(k + p.size());
    }

    return s;
}
```

# 初始化动态数组
```cpp
int len = s.size();
bool* pos = new bool[len];
delete[] pos;
```
