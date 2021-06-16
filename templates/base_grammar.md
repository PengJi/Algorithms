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
