# 整数二分算法
将区间 `[l, r]` 划分成 `[l, mid]` 和 `[mid + 1, r]` 时，  
其更新操作是 `r = mid` 或者 `l = mid + 1`，计算 `mid` 时不需要加 1。
```cpp
int l = 0, r = n - 1;
int bsearch_1(int l, int r) {
    while (l < r) {
        int mid = l + r >> 1;
        if (arr[mid] < target) l = mid + 1;
        else r = mid;
    }
    return l;
}
if (arr[l] != x) cout << "not found" << endl;
```

将区间 `[l, r]` 划分成 `[l, mid - 1]` 和 `[mid, r]` 时，  
其更新操作是 `r = mid - 1` 或者 `l = mid`，此时为了防止死循环，计算mid时需要加1。
```cpp
int l = 0, r = n - 1;
int bsearch_2(int l, int r) {
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (arr[mid] < target) l = mid;
        else r = mid - 1;
    }
    return l;
}
if (arr[l] != x) cout << "not found" << endl;
```

# 浮点数二分算法
```cpp
bool check(double x) {/* ... */} // 检查x是否满足某种性质

double bsearch_3(double l, double r)
{
    const double eps = 1e-6;   // eps 表示精度，取决于题目对精度的要求
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}
```


# 前缀和
原序列中从第 l 个数到第 r 个数的和

## 一维前缀和
`S[i] = a[1] + a[2] + ... a[i]`  
`a[l] + ... + a[r] = S[r] - S[l - 1]`

```cpp
const int N = 100010;

int n, m;
int a[N], s[N];

scanf("%d%d", &n, &m);
for(int i = 1; i <= n; i++) scanf("%d", &a[i]);  // 初始化数组
for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];  // 初始化前缀和
while(m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", s[r] - s[l - 1]);  // 计算区间和
}
```

## 二维前缀和
`S[i, j]` = 第i行j列格子左上部分所有元素的和,  
以 `(x1, y1)` 为左上角，`(x2, y2)` 为右下角的子矩阵的和为：  
`S[x2, y2] - S[x1 - 1, y2] - S[x2, y1 - 1] + S[x1 - 1, y1 - 1]`

```cpp
// 输出子矩阵中所有数的和
const int N = 1010;

int n, m, q;
int s[N][N];

scanf("%d%d%d", &n, &m, &q);

for(int i = 1; i <= n; i ++ )
    for (int j = 1; j <= m; j ++ )
        scanf("%d", &s[i][j]);  // 初始化数组

for(int i = 1; i <= n; i ++ )
    for (int j = 1; j <= m; j ++ )
        s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];  // 前缀和初始化

while(q--) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    printf("%d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);  // 计算区间和
}
```


# 差分
序列中 `[l, r]` 之间的每个数加上 c
差分数组和前缀和数组互为逆运算

## 一维差分
给区间 `[l, r]` 中的每个数加上c：`B[l] += c, B[r + 1] -= c`  

```cpp
const int N = 100010;

int n, m;
int a[N], b[N];  // a 为原数组，b 为差分数组，即 a 为 b 的前缀和数组

void insert(int l, int r, int c) {  // 区间加 c
    b[l] += c;
    b[r + 1] -= c;
}

scanf("%d%d", &n, &m);
for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);  // 初始化原数组
for (int i = 1; i <= n; i ++ ) insert(i, i, a[i]);  // 初始化差分数组

while (m -- ) {
    int l, r, c;
    scanf("%d%d%d", &l, &r, &c);
    insert(l, r, c);  // 区间加 c
}

for (int i = 1; i <= n; i ++ ) b[i] += b[i - 1];  // 从差分数组得出原数组
for (int i = 1; i <= n; i ++ ) printf("%d ", b[i]);
```

## 二维差分矩阵
将选中的子矩阵中的每个元素的值加上 c。
给以 `(x1, y1)` 为左上角，`(x2, y2)` 为右下角的子矩阵中的所有元素加上c：  
`S[x1, y1] += c, S[x2 + 1, y1] -= c, S[x1, y2 + 1] -= c, S[x2 + 1, y2 + 1] += c`

```cpp
const int N = 1010;

int n, m, q;
int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c) {  // 差分矩阵加 c
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

scanf("%d%d%d", &n, &m, &q);

for (int i = 1; i <= n; i ++ )
    for (int j = 1; j <= m; j ++ )
        scanf("%d", &a[i][j]);  // 初始换原数组

for (int i = 1; i <= n; i ++ )
    for (int j = 1; j <= m; j ++ )
        insert(i, j, i, j, a[i][j]);  // 初始化差分矩阵

while (q -- ) {
    int x1, y1, x2, y2, c;
    cin >> x1 >> y1 >> x2 >> y2 >> c;
    insert(x1, y1, x2, y2, c);  // 计算差分矩阵
}

for (int i = 1; i <= n; i ++ )
    for (int j = 1; j <= m; j ++ )
        b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];

for (int i = 1; i <= n; i ++ ) {
    for (int j = 1; j <= m; j ++ ) printf("%d ", b[i][j]);
    puts("");
}
```


# 双指针
常见问题分类：  
(1) 对于一个序列，用两个指针维护一段区间；  
(2) 对于两个序列，维护某种次序，比如归并排序中合并两个有序序列的操作  

1. 判断子序列
   两个序列分别对应一个指针
   ```cpp
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j]) i++;
        j++;
    }
   ```
2. 最长连续不重复子序列
   两个指针分别对应序列的首尾
   ```cpp
    for(int i = 0, j = 0; i < n; i++) {
        b[a[i]]++;
        while(b[a[i]] > 1) {
            b[a[j]]--;
            j++;
        }
        res = max(res, i-j+1);
    }
   ```
3. [数组元素的目标和](https://www.acwing.com/problem/content/802/)
   两个指针分别对应两个数组
   ```cpp
    for (int i = 0, j = m - 1; i < n; i ++ ){
        while (j >= 0 && a[i] + b[j] > x) j -- ;
        if (j >= 0 && a[i] + b[j] == x) cout << i << ' ' << j << endl;
    }
    ```


# 并查集
每个集合用一棵树表示，树根的编号是集合的编号，每个节点存储它的父节点，`p[x]` 表示 `x` 的父节点。

常用操作：
1. 将两个集合合并；
2. 询问两个元素是否在一个集合当中；

判断树根：`if(p[x] == x)`；  
求 x 的集合编号：`while(p[x] != x) x = p[x];`；  
合并两个集合，p[x] 是 x 的集合编号，p[y] 是 y 的集合编号，`p[x] = y`；  


# 位运算
求 n 的第 k 位数字: `n >> k & 1`
返回 n 的最后一位 1：`lowbit(n) = n & -n`

lowbit 示例：  
> 根据计算机负数表示的特点，如一个数字原码是 10001000，他的负数表示形势是补码，就是反码+1，反码是 01110111，加一则是 01111000，二者按位与得到了 1000，就是我们想要的lowbit操作
