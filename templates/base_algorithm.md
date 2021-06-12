# 二分算法
## 将区间[l, r]划分成[l, mid]和[mid + 1, r]时，其更新操作是r = mid或者l = mid + 1;，计算mid时不需要加1。
```cpp
int l = 0, r = n - 1;
while (l < r) {
    int mid = l + r >> 1;
    if (arr[mid] < target) l = mid + 1;
    else r = mid;
}
if (arr[l] != x) cout << "not found" << endl;
```
## 将区间[l, r]划分成[l, mid - 1]和[mid, r]时，其更新操作是r = mid - 1或者l = mid;，此时为了防止死循环，计算mid时需要加1。
```cpp
int l = 0, r = n - 1;
while (l < r) {
    int mid = l + r + 1 >> 1;
    if (arr[mid] < target) l = mid;
    else r = mid - 1;
}
if (arr[l] != x) cout << "not found" << endl;
```


# 前缀和
## 一维前缀和
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
```cpp
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