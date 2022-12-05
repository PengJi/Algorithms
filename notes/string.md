反转字符串
```cpp
reverse(s.begin() + 1, s.end());

s = "abc";
res = string(s.rbegin(), s.rend());
```

分割以空格分隔的字符串
```cpp
string s = "abc def ghi";
stringstrem ss(s);
vector<string> vec;
string word;
while(ss > word) vec.push_back(word);
```

分割字符串 + 类型转换
```cpp
vector<string> vec = {"1:2", "3:4", "5:6"};
int h, m;
for(auto t: vec) {
    sscanf(t.c_str(), "%d:%d", &h, &m);
    cout << h << " " << m;
}
```

整型转换为字符串
```cpp
int num = 10;
string str = to_string(10);
```

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
