# string -> int
```cpp
string str = "111"
int a = atoi(str.c_str())  // c 语言形式
int b = stoi(str)  // c++ 形式

// 转换为 long long
string str = "98848927274872"
long long c = stoll(str)

// 转化为其他形式
stol(long)
stof(float)
stod(double)
```

# int -> string
```cpp
to_string(10)
```

# 字符串分割并转换
```cpp
t = "20:20"
int h, m;
sscanf(t.c_str(), "%d:%d", &h, &m);
```

# 比较字符，忽略大小写
`a == b && a == b ^ 32`
在ascii码里，大小写字母之间的差是 32，比如 `'a' - 'A' = 32`
