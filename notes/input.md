# C++输入

## 多行输入
输入
3
7 4 7
2 50
```cpp
int n;  // 先声明参数n
cin >> n;  // 输入n
vector<long long> a(n+1);
for(int i = 1; i <= n; ++i){
    cin >> a[i];  // 7 4 7 是根据n产生的
}

int k,d;  // 声明 k d 
cin >> k >> d;  // 输入 k d
// 再调用函数
```

## 输入单行
```cpp
vector<int> v;
int a;
while(cin>>a){
    v.push_back(a);
    if(cin.get=='\n')
        break;
}
```

## 输入二维数组
```cpp
#include "stdlib.h"
#include <iostream>
#include<vector>
#include <iomanip>
using namespace std;
 
int main()
{
    int m, n;
    // cout << "请输入行和列：";
    cin >> m >> n;
 
    // 注意下面这一行：vector <int后两个 "> "之间要有空格！否则会被认为是重载 "> > "。   
    vector<vector<int> > p(m, vector<int>(n));
 
    // cout << "请输入数据：";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> p[i][j];
 
    // cout << "输出数据：" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(3) << p[i][j];
        cout << endl;
    }
    system("pause");
    return 0;
}
```

[OJ在线编程常见输入输出练习](https://www.nowcoder.com/exam/test/80567089/detail?pid=27976983#question)
