# 整数二分算法


# 浮点数二分算法


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


# 位运算


# 高精度加法
```cpp
// C = A + B, A >= 0, B >= 0
vector<int> add(vector<int> &A, vector<int> &B) {
    if (A.size() < B.size()) return add(B, A);

    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i ++ ) {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if (t) C.push_back(t);
    return C;
}
```


# 高精度减法
```cpp
// C = A - B, 满足A >= B, A >= 0, B >= 0
vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i ++ ) {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
```


# 高精度乘低精度
```cpp
// C = A * b, A >= 0, b >= 0
vector<int> mul(vector<int> &A, int b) {
    vector<int> C;

    int t = 0;
    for (int i = 0; i < A.size() || t; i ++ ) {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}
```


# 高精度除以低精度
```cpp
// A / b = C ... r, A >= 0, b > 0
vector<int> div(vector<int> &A, int b, int &r) {
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i -- ) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
```


# 离散化
```cpp
vector<int> alls; // 存储所有待离散化的值
sort(alls.begin(), alls.end()); // 将所有值排序
alls.erase(unique(alls.begin(), alls.end()), alls.end());   // 去掉重复元素

// 二分求出x对应的离散化的值
int find(int x) {  // 找到第一个大于等于x的位置
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1; // 映射到1, 2, ...n
}
```

# 参考
[https://www.acwing.com/blog/content/277/](https://www.acwing.com/blog/content/277/)
