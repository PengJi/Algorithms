string -> int
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

// 字符串分割并转换
t = "20:20"
int h, m;
sscanf(t.c_str(), "%d:%d", &h, &m);
```
