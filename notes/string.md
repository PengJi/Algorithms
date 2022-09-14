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

反转字符串
```cpp
reverse(s.begin() + 1, s.end());
```