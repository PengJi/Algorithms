# 训练
思路 -> 将思路转换为代码


# 模拟
- [x] [15. 三数之和](https://leetcode-cn.com/problems/3sum/)  
- [x] [26. 删除排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)  
- [x] [189. 旋转数组](https://leetcode-cn.com/problems/rotate-array/)  
- [x] [88. 合并两个有序数组](https://leetcode-cn.com/problems/merge-sorted-array/)  
- [x] [66. 加一](https://leetcode-cn.com/problems/plus-one/)  
- [x] [36. 有效的数独](https://leetcode-cn.com/problems/valid-sudoku/description/) 


# 位运算

## 位运算符
|    含义   | 运算符 | 示例 |
| ---------- | --- | --- | 
| 左移 | << | 0011 => 0110 |
| 右移 | >> | 0110 => 0011 | 
| 按位或 | | | 0011 1011 => 1011 | 
| 按位与 | & | 0011 & 1011 =>  0011 | 
| 按位取反 | ~ | 0011 => 1100 | 
| 按位异或（相同为零不同为一）| ^ | 0011 ^ 1011 => 1000 |

## 位运算技巧
1. 将 x 最右边的 n 位清零：`x & (~0 << n)`
2. 获取 x 的第 n 位值（0 或者 1）： `(x >> n) & 1`
3. 获取 x 的第 n 位的幂值：`x& (1 << n)`
4. 仅将第 n 位置为 1：`x | (1 << n)`
5. 仅将第 n 位置为 0：`x & (~ (1 << n))`
6. 将 x 最高位至第 n 位（含）清零：`x & ((1 << n) -1)`
7. 将第 n 位至第 0 位（含）清零：`x& (~ ((1 << (n + 1)) -1))`
8. 运算特点
异或运算：`x ^ 0 = x​ ， x ^ 1 = ~x`
与运算：`x & 0 = 0 ， x & 1 = x`

## 位运算示例
1. 判断奇偶：  
`x % 2 == 1` —> `(x & 1) == 1`  
`x % 2 == 0` —> `(x & 1) == 0`

2. 除2
即： `x = x / 2;` —> `x >>= 1;`
`mid = (left + right) / 2;` —> `mid = (left + right) >> 1;`

3. 清零最低位的 1
`X = X & (X-1)` 

4. 得到最低位的 1
`X & -X` 
> 根据计算机负数表示的特点，如一个数字原码是 10001000，他的负数表示形式是补码，就是反码 +1，反码是 01110111，加一则是 01111000，二者按位与得到了 1000，就是我们想要的 lowbit 操作。
反码加一则是补码（负数形式）：`~X + 1 = -X`


5. 统计一个数中 1 的个数
```cpp
int cnt = 0;
while(num) {
    cnt += num & 1;
    num >>= 1;
}
```

## 题目
- [x] [191. 为1的个数](https://leetcode-cn.com/problems/number-of-1-bits/)  
- [x] [231. 2的幂](https://leetcode-cn.com/problems/power-of-two/)  
- [x] [190. 颠倒二进制位](https://leetcode-cn.com/problems/reverse-bits/)  
- [x] [51. N皇后](https://leetcode-cn.com/problems/n-queens/description/)  
- [x] [52. N皇后 II](https://leetcode-cn.com/problems/n-queens-ii/description/)


# 二分查找

## 整数二分算法
将区间 `[l, r]` 划分成 `[l, mid]` 和 `[mid + 1, r]` 时，  
其更新操作是 `r = mid` 或者 `l = mid + 1`，计算 `mid` 时不需要加 1。
```cpp
vector<int> arr(n);
int l = 0, r = n - 1;
int bsearch_1(int l, int r, int targe) {
    while (l < r) {
        int mid = l + r >> 1;
        if (arr[mid] < target) l = mid + 1;
        else r = mid;
    }
    return l;
}
// 如果没找到，则返回的下标是 l+1
if (arr[l] != target) cout << "not found" << endl;
```

将区间 `[l, r]` 划分成 `[l, mid - 1]` 和 `[mid, r]` 时，  
其更新操作是 `r = mid - 1` 或者 `l = mid`，此时为了防止死循环，计算mid时需要加1。
```cpp
vector<int> arr(n);
int l = 0, r = n - 1;
int bsearch_2(int l, int r, int target) {
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (arr[mid] < target) l = mid;
        else r = mid - 1;
    }
    return l;
}
if (arr[l] != target) cout << "not found" << endl;
```

## 浮点数二分算法
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

## 题目
- [x] [69. x 的平方根](https://leetcode-cn.com/problems/sqrtx/)  
- [x] [367. 有效的完全平方数](https://leetcode-cn.com/problems/valid-perfect-square/)  
- [x] [33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)  
- [x] [74. 搜索二维矩阵](https://leetcode-cn.com/problems/search-a-2d-matrix/)  
- [x] [153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)  


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
        int tmp = a[i];
        b[tmp]++;
        while(tmp > 1) {
            b[tmp]--;
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


# 滑动窗口
- [x] [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)
- [x] [76. 最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/)
- [x] [438. 找到字符串中所有字母异位词](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/)
- [x] [567. 字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/)


# 并查集
用于组团、配对问题

基本操作：  
* makeSet(s)：建立一个新的并查集，其中包含 s 个单元素集合。
* unionSet(x, y)：把元素 x 和元素 y 所在的集合合并，要求 x 和 y 所在的集合不相交，如果相交则不合并。
* find(x)：找到元素 x 所在的集合的代表，该操作也可以用于判断两个元素是否位于同一个集合，只要将它们各自的代表比较一下就可以了。

- [x] [547. 朋友圈](https://leetcode-cn.com/problems/friend-circles/)
- [x] [130. 被围绕的区域](https://leetcode-cn.com/problems/surrounded-regions/)
- [x] [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/) 


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


# 字符串

## 字符串基础问题
- [x] [8. 字符串转换整数 (atoi)](https://leetcode-cn.com/problems/string-to-integer-atoi/)
- [x] [709. 转换成小写字母](https://leetcode-cn.com/problems/to-lower-case/)
- [x] [58. 最后一个单词的长度](https://leetcode-cn.com/problems/length-of-last-word/)
- [x] [771. 宝石与石头](https://leetcode-cn.com/problems/jewels-and-stones/)
- [x] [387. 字符串中的第一个唯一字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/)

## 字符串操作问题
- [x] [14. 最长公共前缀](https://leetcode-cn.com/problems/longest-common-prefix/description/)
- [x] [344. 反转字符串](https://leetcode-cn.com/problems/reverse-string/)
- [x] [541. 反转字符串 II](https://leetcode-cn.com/problems/reverse-string-ii/)
- [x] [151. 翻转字符串里的单词](https://leetcode-cn.com/problems/reverse-words-in-a-string/)
- [x] [557. 反转字符串中的单词 III](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)
- [x] [917. 仅仅反转字母](https://leetcode-cn.com/problems/reverse-only-letters/)

## 异位词问题
- [x] [242. 有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/)
- [x] [49. 字母异位词分组](https://leetcode-cn.com/problems/group-anagrams/)
- [x] [438. 找到字符串中所有字母异位词](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/)

## 回文串问题
- [x] [125. 验证回文串](https://leetcode-cn.com/problems/valid-palindrome/)
- [x] [680. 验证回文字符串 Ⅱ](https://leetcode-cn.com/problems/valid-palindrome-ii/)
- [x] [5. 最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)

## 最长子串、子序列问题
- [x] [1143. 最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence/)
- [x] [72. 编辑距离](https://leetcode-cn.com/problems/edit-distance/)
- [x] [5. 最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)

## 字符串 + DP 问题
- [x] [10. 正则表达式匹配](https://leetcode-cn.com/problems/regular-expression-matching/)
- [x] [44. 通配符匹配](https://leetcode-cn.com/problems/wildcard-matching/)
- [x] [115. 不同的子序列](https://leetcode-cn.com/problems/distinct-subsequences/)


# 单链表
```cpp
// head 存储链表头，e[] 存储节点的值，ne[] 存储节点的next指针，idx 表示当前用到了哪个节点
int head, e[N], ne[N], idx;

// 初始化
void init() {
    head = -1;
    idx = 0;
}

// 在链表头插入一个数 a
void insert(int a) {
    e[idx] = a;
    ne[idx] = head;
    head = idx ++ ;
}

// 将头结点删除，需要保证头结点存在
void remove() {
    head = ne[head];
}
```


# 双链表
```cpp
// e[] 表示节点的值，l[] 表示节点的左指针，r[] 表示节点的右指针，idx 表示当前用到了哪个节点
int e[N], l[N], r[N], idx;

// 初始化
void init() {
    //0是左端点，1是右端点
    r[0] = 1, l[1] = 0;
    idx = 2;
}

// 在节点a的右边插入一个数x
void insert(int a, int x) {
    e[idx] = x;
    l[idx] = a, r[idx] = r[a];
    l[r[a]] = idx, r[a] = idx ++ ;
}

// 删除节点a
void remove(int a) {
    l[r[a]] = l[a];
    r[l[a]] = r[a];
}
```

## 题目
- [x] [206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/)  
- [x] [24. 两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/)  
- [x] [141. 环形链表](https://leetcode.cn/problems/linked-list-cycle/)  
- [x] [142. 环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/)  
- [x] [25. K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/)
- [x] [21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/) 


# 栈
```cpp
// tt表示栈顶
int stk[N], tt = 0;

// 向栈顶插入一个数
stk[++tt] = x;

// 从栈顶弹出一个数
tt -- ;

// 栈顶的值
stk[tt];

// 判断栈是否为空
if (tt > 0) {
}
```

## 题目
- [x] [84. 柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)



# 队列
## 普通队列
```cpp
// hh 表示队头，tt表示队尾
int q[N], hh = 0, tt = -1;

// 向队尾插入一个数
q[++tt] = x;

// 从队头弹出一个数
hh++ ;

// 队头的值
q[hh];

// 判断队列是否为空
if (hh <= tt) {
}
```

## 循环队列
```cpp
// hh 表示队头，tt表示队尾的后一个位置
int q[N], hh = 0, tt = 0;

// 向队尾插入一个数
q[tt++] = x;
if (tt == N) tt = 0;

// 从队头弹出一个数
hh ++ ;
if (hh == N) hh = 0;

// 队头的值
q[hh];

// 判断队列是否为空
if (hh != tt) {
}
```


# 单调栈
常见模型：找出每个数左边（右边）离它最近的比它大/小的数
```cpp
int tt = 0;
for (int i = 1; i <= n; i ++ ) {
    while (tt && check(stk[tt], i)) tt-- ;
    stk[++tt] = i;
}
```


# 单调队列
常见模型：找出滑动窗口中的最大值/最小值
```cpp
int hh = 0, tt = -1;
for (int i = 0; i < n; i ++ ) {
    while (hh <= tt && check_out(q[hh])) hh ++ ;  // 判断队头是否滑出窗口
    while (hh <= tt && check(q[tt], i)) tt -- ;
    q[ ++ tt] = i;
}
```


# KMP
```cpp
// s[]是长文本，p[]是模式串，n是s的长度，m是p的长度
求模式串的Next数组：
for (int i = 2, j = 0; i <= m; i ++ ) {
    while (j && p[i] != p[j + 1]) j = ne[j];
    if (p[i] == p[j + 1]) j ++ ;
    ne[i] = j;
}

// 匹配
for (int i = 1, j = 0; i <= n; i ++ ) {
    while (j && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) j ++ ;
    if (j == m) {
        j = ne[j];
        // 匹配成功后的逻辑
    }
}
```


# Trie 树
```cpp
int son[N][26], cnt[N], idx;
// 0号点既是根节点，又是空节点
// son[][]存储树中每个节点的子节点
// cnt[]存储以每个节点结尾的单词数量

// 插入一个字符串
void insert(char *str) {
    int p = 0;
    for (int i = 0; str[i]; i ++ ) {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++ ;
}

// 查询字符串出现的次数
int query(char *str) {
    int p = 0;
    for (int i = 0; str[i]; i ++ ) {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}
```


# 并查集
每个集合用一棵树表示，树根的编号是集合的编号，每个节点存储它的父节点，`p[x]` 表示 `x` 的父节点。

常用操作：
1. 将两个集合合并；
2. 询问两个元素是否在一个集合当中；

判断树根：`if(p[x] == x)`；  
求 x 的集合编号：`if(p[x] != x) p[x] = find(p[x]);` 或 `while(p[x] != x) x = p[x];`；  
合并两个集合，p[x] 是 x 的集合编号，p[y] 是 y 的集合编号，`p[x] = y`；  

## 朴素并查集
```cpp
int p[N]; // 存储每个点的祖宗节点

// 返回x的祖宗节点
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

// 初始化，假定节点编号是 1~n
for (int i = 1; i <= n; i ++ ) p[i] = i;

// 合并a和b所在的两个集合：
p[find(a)] = find(b);
```

## 维护size的并查集
```cpp
int p[N], size[N];
// p[]存储每个点的祖宗节点, size[]只有祖宗节点的有意义，表示祖宗节点所在集合中的点的数量

// 返回x的祖宗节点
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

// 初始化，假定节点编号是 1~n
for (int i = 1; i <= n; i ++ ) {
    p[i] = i;
    size[i] = 1;
}

// 合并a和b所在的两个集合：
size[find(b)] += size[find(a)];
p[find(a)] = find(b);
```

## 维护到祖宗节点距离的并查集
```cpp
int p[N], d[N];
//p[]存储每个点的祖宗节点, d[x]存储x到p[x]的距离

// 返回x的祖宗节点
int find(int x) {
    if (p[x] != x) {
        int u = find(p[x]);
        d[x] += d[p[x]];
        p[x] = u;
    }
    return p[x];
}

// 初始化，假定节点编号是1~n
for (int i = 1; i <= n; i ++ ) {
    p[i] = i;
    d[i] = 0;
}

// 合并a和b所在的两个集合：
p[find(a)] = find(b);
d[find(a)] = distance; // 根据具体问题，初始化find(a)的偏移量
```


# 堆
```cpp
// h[N]存储堆中的值, h[1]是堆顶，x的左儿子是2x, 右儿子是2x + 1
// ph[k]存储第k个插入的点在堆中的位置
// hp[k]存储堆中下标是k的点是第几个插入的
int h[N], ph[N], hp[N], size;

// 交换两个点，及其映射关系
void heap_swap(int a, int b) {
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u) {
    int t = u;
    if (u * 2 <= size && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t) {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u) {
    while (u / 2 && h[u] < h[u / 2]) {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

// O(n)建堆
for (int i = n / 2; i; i -- ) down(i);
```


# 哈希表
哈希表（Hash table 也叫散列表，是根据关键码值（ Key value）而直接进行访问的数据结构 。
它通过把关键码值映射到表中一个位置来访问记录，以加快查找的
速度。
这个映射函数叫作散列函数（ Hash Function 存放记录的数组叫作哈希表（或散列表 ）。

## 拉链法
```cpp
int h[N], e[N], ne[N], idx;

// 向哈希表中插入一个数
void insert(int x) {
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx ++ ;
}

// 在哈希表中查询某个数是否存在
bool find(int x) {
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i] == x)
            return true;

    return false;
}
```

## 开放寻址法
```cpp
int h[N];

// 如果x在哈希表中，返回x的下标；如果x不在哈希表中，返回x应该插入的位置
int find(int x) {
    int t = (x % N + N) % N;
    while (h[t] != null && h[t] != x) {
        t ++ ;
        if (t == N) t = 0;
    }
    return t;
}
```

## 字符串哈希
核心思想：将字符串看成P进制数，P的经验值是131或13331，取这两个值的冲突概率低
小技巧：取模的数用2^64，这样直接用unsigned long long存储，溢出的结果就是取模的结果
```cpp
typedef unsigned long long ULL;
ULL h[N], p[N]; // h[k]存储字符串前k个字母的哈希值, p[k]存储 P^k mod 2^64

// 初始化
p[0] = 1;
for (int i = 1; i <= n; i ++ )
{
    h[i] = h[i - 1] * P + str[i];
    p[i] = p[i - 1] * P;
}

// 计算子串 str[l ~ r] 的哈希值
ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}
```

## 题目
- [x] [1. 两数之和](https://leetcode-cn.com/problems/two-sum/description/)  
- [x] [49. 字母异位词分组](https://leetcode-cn.com/problems/group-anagrams/)  
- [x] [242. 有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/description/) 


# 树与图的存储
树是一种特殊的图，与图的存储方式相同。
对于无向图中的边ab，存储两条有向边 `a->b, b->a`。
因此我们可以只考虑有向图的存储。

(1) 邻接矩阵：g[a][b] 存储边a->b

(2) 邻接表：
```cpp
// 对于每个点k，开一个单链表，存储k所有可以走到的点。h[k]存储这个单链表的头结点
int h[N], e[N], ne[N], idx;

// 添加一条边a->b
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

// 初始化
idx = 0;
memset(h, -1, sizeof h);
```


# 树与图的遍历
时间复杂度 `O(n+m)`, `n` 表示点数，`m` 表示边数
深度优先遍历
```cpp
int dfs(int u) {
    st[u] = true; // st[u] 表示点u已经被遍历过

    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) dfs(j);
    }
}
```

宽度优先遍历
```cpp
queue<int> q;
st[1] = true; // 表示1号点已经被遍历过
q.push(1);

while (q.size()) {
    int t = q.front();
    q.pop();

    for (int i = h[t]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            st[j] = true; // 表示点j已经被遍历过
            q.push(j);
        }
    }
}
```


# 拓扑排序
时间复杂度 `O(n+m)`, n 表示点数，m 表示边数
```cpp
bool topsort() {
    int hh = 0, tt = -1;

    // d[i] 存储点 i 的入度
    for (int i = 1; i <= n; i ++ )
        if (!d[i])
            q[ ++ tt] = i;

    while (hh <= tt) {
        int t = q[hh ++ ];

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (-- d[j] == 0)
                q[ ++ tt] = j;
        }
    }

    // 如果所有点都入队了，说明存在拓扑序列；否则不存在拓扑序列。
    return tt == n - 1;
}
```


# 朴素 dijkstra 算法
时间复杂是 `O(n^2+m)`, n 表示点数，m 表示边数
```cpp
int g[N][N];  // 存储每条边
int dist[N];  // 存储1号点到每个点的最短距离
bool st[N];   // 存储每个点的最短路是否已经确定

// 求1号点到n号点的最短路，如果不存在则返回-1
int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < n - 1; i ++ ) {
        int t = -1;     // 在还未确定最短路的点中，寻找距离最小的点
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        // 用t更新其他点的距离
        for (int j = 1; j <= n; j ++ )
            dist[j] = min(dist[j], dist[t] + g[t][j]);

        st[t] = true;
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}
```


# 堆优化版 dijkstra
时间复杂度 `O(mlogn)`, n 表示点数，m 表示边数
```cpp
typedef pair<int, int> PII;

int n;      // 点的数量
int h[N], w[N], e[N], ne[N], idx;       // 邻接表存储所有边
int dist[N];        // 存储所有点到1号点的距离
bool st[N];     // 存储每个点的最短距离是否已确定

// 求1号点到n号点的最短距离，如果不存在，则返回-1
int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});      // first存储距离，second存储节点编号

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > distance + w[i]) {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}
```


# Bellman-Ford算法 
时间复杂度 `O(nm)`, n 表示点数，m 表示边数
```cpp
int n, m;       // n表示点数，m表示边数
int dist[N];        // dist[x]存储1到x的最短路距离

struct Edge {    // 边，a表示出点，b表示入点，w表示边的权重
    int a, b, w;
}edges[M];

// 求1到n的最短路距离，如果无法从1走到n，则返回-1。
int bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    // 如果第n次迭代仍然会松弛三角不等式，就说明存在一条长度是n+1的最短路径，由抽屉原理，路径中至少存在两个相同的点，说明图中存在负权回路。
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < m; j ++ ) {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            if (dist[b] > dist[a] + w)
                dist[b] = dist[a] + w;
        }
    }

    if (dist[n] > 0x3f3f3f3f / 2) return -1;
    return dist[n];
}
```


# spfa 算法（队列优化的Bellman-Ford算法）
时间复杂度 平均情况下 `O(m)`，最坏情况下 `O(nm)`, n 表示点数，m 表示边数
```cpp
int n;      // 总点数
int h[N], w[N], e[N], ne[N], idx;       // 邻接表存储所有边
int dist[N];        // 存储每个点到1号点的最短距离
bool st[N];     // 存储每个点是否在队列中

// 求1号点到n号点的最短路距离，如果从1号点无法走到n号点则返回-1
int spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while (q.size()) {
        auto t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j])     // 如果队列中已存在j，则不需要将j重复插入
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}
```


# spfa 判断图中是否存在负环
时间复杂度是 `O(nm)`, n 表示点数，m 表示边数
```cpp
int n;      // 总点数
int h[N], w[N], e[N], ne[N], idx;       // 邻接表存储所有边
int dist[N], cnt[N];        // dist[x]存储1号点到x的最短距离，cnt[x]存储1到x的最短路中经过的点数
bool st[N];     // 存储每个点是否在队列中

// 如果存在负环，则返回true，否则返回false。
bool spfa() {
    // 不需要初始化dist数组
    // 原理：如果某条最短路径上有n个点（除了自己），那么加上自己之后一共有n+1个点，由抽屉原理一定有两个点相同，所以存在环。

    queue<int> q;
    for (int i = 1; i <= n; i ++ ) {
        q.push(i);
        st[i] = true;
    }

    while (q.size()) {
        auto t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;       // 如果从1号点到x的最短路中包含至少n个点（不包括自己），则说明存在环
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
}
```


# floyd算法
时间复杂度是 `O(n3)`, n 表示点数
```cpp
初始化：
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;

// 算法结束后，d[a][b]表示a到b的最短距离
void floyd()
{
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
```


# 朴素版prim算法
时间复杂度是 `O(n2+m)`, n 表示点数，m 表示边数
```cpp
int n;      // n表示点数
int g[N][N];        // 邻接矩阵，存储所有边
int dist[N];        // 存储其他点到当前最小生成树的距离
bool st[N];     // 存储每个点是否已经在生成树中


// 如果图不连通，则返回INF(值是0x3f3f3f3f), 否则返回最小生成树的树边权重之和
int prim() {
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i ++ ) {
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (i && dist[t] == INF) return INF;

        if (i) res += dist[t];
        st[t] = true;

        for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], g[t][j]);
    }

    return res;
}
```


# Kruskal 算法 
时间复杂度是 `O(mlogm)`, n 表示点数，m 表示边数
```cpp
int n, m;       // n是点数，m是边数
int p[N];       // 并查集的父节点数组

struct Edge {    // 存储边
    int a, b, w;

    bool operator< (const Edge &W)const
    {
        return w < W.w;
    }
}edges[M];

int find(int x) {    // 并查集核心操作
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal() {
    sort(edges, edges + m);

    for (int i = 1; i <= n; i ++ ) p[i] = i;    // 初始化并查集

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i ++ ) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a), b = find(b);
        if (a != b) {    // 如果两个连通块不连通，则将这两个连通块合并
            p[a] = b;
            res += w;
            cnt ++ ;
        }
    }

    if (cnt < n - 1) return INF;
    return res;
}
```


# 染色法判别二分图
时间复杂度是 `O(n+m)`, n 表示点数，m 表示边数
```cpp
int n;      // n表示点数
int h[N], e[M], ne[M], idx;     // 邻接表存储图
int color[N];       // 表示每个点的颜色，-1表示未染色，0表示白色，1表示黑色

// 参数：u表示当前节点，c表示当前点的颜色
bool dfs(int u, int c) {
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (color[j] == -1) {
            if (!dfs(j, !c)) return false;
        }
        else if (color[j] == c) return false;
    }

    return true;
}

bool check() {
    memset(color, -1, sizeof color);
    bool flag = true;
    for (int i = 1; i <= n; i ++ )
        if (color[i] == -1)
            if (!dfs(i, 0)) {
                flag = false;
                break;
            }
    return flag;
}
```


# 匈牙利算法
时间复杂度是 `O(nm)`, n 表示点数，m 表示边数
```cpp
int n1, n2;     // n1表示第一个集合中的点数，n2表示第二个集合中的点数
int h[N], e[M], ne[M], idx;     // 邻接表存储所有边，匈牙利算法中只会用到从第一个集合指向第二个集合的边，所以这里只用存一个方向的边
int match[N];       // 存储第二个集合中的每个点当前匹配的第一个集合中的点是哪个
bool st[N];     // 表示第二个集合中的每个点是否已经被遍历过

bool find(int x) {
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            st[j] = true;
            if (match[j] == 0 || find(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }

    return false;
}

// 求最大匹配数，依次枚举第一个集合中的每个点能否匹配第二个集合中的点
int res = 0;
for (int i = 1; i <= n1; i ++ ) {
    memset(st, false, sizeof st);
    if (find(i)) res ++ ;
}
```


# 树
## 二叉树结构体
```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}
```


## 二叉树遍历
[二叉树遍历(先序、中序、后序)](https://www.jianshu.com/p/456af5480cee)
```python
def preorder(self, root):
    if root:
        self.traverse_path.append(root.val)
        self.preorder(root.left)
        self.preorder(root.right)

def inorder(self, root):
    if root:
        self.inorder(root.left)
        self.traverse_path.append(root.val)
        self.inorder(root.right)

def postorder(self, root):
    if root:
        self.postorder(root.left)
        self.postorder(root.right)
        self.traverse_path.append(root.val)
```

## 二叉树示例
[https://visualgo.net/zh/bst](https://visualgo.net/zh/bst)

# 题目
- [x] [144. 二叉树的前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/)  
- [x] [589. N叉树的前序遍历](https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/description/)  
- [x] [429. N叉树的层序遍历](https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/)  
- [x] [590. N叉树的后序遍历](https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/)  
- [x] [297. 二叉树的序列化与反序列化](https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/)
- [x] [105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)


# 红黑树
红黑树是一种近似平衡的二叉搜索树（Binary Search Tree），它能够确保任何一个结点的左右子树的高度差小于两倍。
满足以下条件：
* 每个节点要么是红色，要么是黑色
* 根节点是黑色
* 每个叶结点（nil节点，空节点）是黑色的
* 不能有相邻接的两个红色节点
* 从任一节点到其每个叶子的所有路径都包含相同数目的黑色节点


# 字典树
字典树，即 Trie 树，又称单词查找树或键树，是一种树形结构。典型应用是用于统计和排序大量的字符串（但不仅限于字符串），所以经常被搜索引擎系统用于文本词频统计。

它的优点是：最大限度地减少无谓的字符串比较，查询效率比哈希表高。

基本性质：
1. 结点本身不存完整单词；
2. 从根结点到某一结点，路径上经过的字符连接起来，为该结点对应的字符串；
3. 每个结点的所有子结点路径代表的字符都不相同。

Trie 树的核心思想是空间换时间。利用字符串的公共前缀来降低查询时间的开销以达到提高效率的目的。

## 题目
- [x] [208. 实现 Trie (前缀树)](https://leetcode-cn.com/problems/implement-trie-prefix-tree/#/description)  
- [x] [212. 单词搜索 II](https://leetcode-cn.com/problems/word-search-ii/)
 

# 深度优先搜索

## 递归写法
```python
visited = set() 

def dfs(node, visited):
    if node in visited: # terminator
        # already visited 
        return 

    visited.add(node) 

    # process current node here. 
    ...
    for next_node in node.children(): 
        if next_node not in visited: 
            dfs(next_node, visited)
```

## 非递归写法
```python
def DFS(self, tree): 

    if tree.root is None: 
        return [] 

    visited, stack = [], [tree.root]

    while stack: 
        node = stack.pop() 
        visited.add(node)

        process (node) 
        nodes = generate_related_nodes(node) 
        stack.push(nodes) 

    # other processing work 
    ...
```

# 广度优先搜索
```python
def BFS(graph, start, end):
    visited = set()
    queue = [] 
    queue.append([start]) 

    while queue: 
        node = queue.pop() 
        visited.add(node)

        process(node) 
        nodes = generate_related_nodes(node) 
        queue.push(nodes)

    # other processing work 
    ...
```

## 题目
- [x] [102. 二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/#/description)  
- [x] [515. 在每个树行中找最大值](https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/)  
- [x] [127. 单词接龙](https://leetcode-cn.com/problems/word-ladder/description/)  
- [x] [126. 单词接龙 II](https://leetcode-cn.com/problems/word-ladder-ii/description/) 
- [x] [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)  
- [x] [529. 扫雷游戏](https://leetcode-cn.com/problems/minesweeper/description/) 

## 双向BFS
- [x] [127. 单词接龙](https://leetcode-cn.com/problems/word-ladder/)    
- [x] [433. 最小基因变化](https://leetcode-cn.com/problems/minimum-genetic-mutation/)


# 启发式搜索（`A*`）
启发式函数： `h(n)`，它用来评价哪些结点最有希望的是一个我们要找的结点，
`h(n)` 会返回一个非负实数,也可以认为是从结点n的目标结点路径的估计成本。

启发式函数是一种告知搜索方向的方法。它提供了一种明智的方法来猜测哪个邻居结点会导向一个目标。

## 题目
- [x] [1091. 二进制矩阵中的最短路径](https://leetcode-cn.com/problems/shortest-path-in-binary-matrix/)  
- [x] [773. 滑动谜题](https://leetcode-cn.com/problems/sliding-puzzle/)  
- [x] [37. 解数独](https://leetcode-cn.com/problems/sudoku-solver/) 


# 回溯法
回溯法采用试错的思想，它尝试分步的去解决一个问题。
在分步解决问题的过程中，当它通过尝试发现现有的分步答案不能得到有效的正确的解答的时候，它将取消上一步甚至是上几步的计算，再通过其它的可能的分步解答再次尝试寻找问题的答案。  

回溯法通常用最简单的递归方法来实现，在反复重复上述的步骤后可能出现两种情况：
1. 找到一个可能存在的正确的答案
2. 在尝试了所有可能的分步方法后宣告该问题没有答案

在最坏的情况下，回溯法会导致一次复杂度为指数时间的计算。

## 题目
- [x] [46. 全排列](https://leetcode-cn.com/problems/permutations/)  
- [x] [47. 全排列 II](https://leetcode-cn.com/problems/permutations-ii/)  
- [x] [39. 组合总和](https://leetcode-cn.com/problems/combination-sum/)  
- [x] [40. 组合总和 II](https://leetcode-cn.com/problems/combination-sum-ii/)  
- [x] [78. 子集](https://leetcode-cn.com/problems/subsets/)  
- [x] [90. 子集 II](https://leetcode-cn.com/problems/subsets-ii/)  
- [x] [22. 括号生成](https://leetcode-cn.com/problems/generate-parentheses/)  
- [x] [51. N皇后](https://leetcode-cn.com/problems/n-queens/)   
- [x] [37. 解数独](https://leetcode-cn.com/problems/sudoku-solver/#/description)  
- [x] [17. 电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)  


# 分治
```python
def divide_conquer(problem, param1, param2, ...): 
  # recursion terminator 
  if problem is None: 
    print_result 
    return 

  # prepare data 
  data = prepare_data(problem) 
  subproblems = split_problem(problem, data) 

  # conquer subproblems 
  subresult1 = self.divide_conquer(subproblems[0], p1, ...) 
  subresult2 = self.divide_conquer(subproblems[1], p1, ...) 
  subresult3 = self.divide_conquer(subproblems[2], p1, ...) 
  …

  # process and generate the final result 
  result = process_result(subresult1, subresult2, subresult3, …)
    
  # revert the current level states
```


# 动态规划
动态规划的题目分为两大类，一种是求最优解类，典型问题是背包问题，另一种就是计数类，比如统计方案数。  
关键点：  
* 最优子结构 opt[n] = best_of(opt[n-1], opt[n-2], …)  
* 储存中间状态：opt[i]  
* 递推公式（美其名曰：状态转移方程或者 DP 方程）   
Fib: opt[i] = opt[n-1] + opt[n-2]   
二维路径：opt[i,j] = opt[i+1][j] + opt[i][j+1] (且判断a[i,j]是否空地）

动态规划做题步骤  
* 明确 dp[i] 应该表示什么（二维情况：dp[i][j]）； 
* 确定初始条件，如：dp[0]。   
* 根据 dp[i] 和 dp[i-1] 的关系得出状态转移方程； 

## 题目
- [x] [70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)  
- [x] [120. 三角形最小路径和](https://leetcode-cn.com/problems/triangle/)  
- [x] [53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)  
- [x] [152. 乘积最大子数组](https://leetcode-cn.com/problems/maximum-product-subarray/description/)  
- [x] [322. Coin Change](https://leetcode.com/problems/coin-change/description/)  
- [x] [198. 打家劫舍](https://leetcode-cn.com/problems/house-robber/)  
- [x] [213. 打家劫舍 II](https://leetcode-cn.com/problems/house-robber-ii/description/)  
- [x] [121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/#/description)  
- [x] [122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)  
- [x] [123. 买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)  
- [x] [309. 最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)  
- [x] [188. 买卖股票的最佳时机 IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)  
- [x] [714. 买卖股票的最佳时机含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)  
- [x] [279. 完全平方数](https://leetcode-cn.com/problems/perfect-squares/)  
- [x] [72. 编辑距离](https://leetcode-cn.com/problems/edit-distance/)  
- [x] [55. 跳跃游戏](https://leetcode-cn.com/problems/jump-game/)  
- [x] [45. 跳跃游戏 II](https://leetcode-cn.com/problems/jump-game-ii/)  
- [x] [62. 不同路径](https://leetcode-cn.com/problems/unique-paths/)  
- [x] [63. 不同路径 II](https://leetcode-cn.com/problems/unique-paths-ii/)  
- [x] [980. 不同路径 III](https://leetcode-cn.com/problems/unique-paths-iii/)  
- [x] [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/)    
- [x] [518. 零钱兑换 II](https://leetcode-cn.com/problems/coin-change-2/)  
- [x] [32. 最长有效括号](https://leetcode-cn.com/problems/longest-valid-parentheses/)   
- [x] [64. 最小路径和](https://leetcode-cn.com/problems/minimum-path-sum/)  
- [x] [91. 解码方法](https://leetcode-cn.com/problems/decode-ways/)  
- [x] [221. 最大正方形](https://leetcode-cn.com/problems/maximal-square/)  
- [x] [363. 矩形区域不超过 K 的最大数值和](https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/)  
- [x] [403. 青蛙过河](https://leetcode-cn.com/problems/frog-jump/)  
- [x] [410. 分割数组的最大值](https://leetcode-cn.com/problems/split-array-largest-sum/)  
- [x] [552. 学生出勤记录 II](https://leetcode-cn.com/problems/student-attendance-record-ii/)  
- [x] [621. 任务调度器](https://leetcode-cn.com/problems/task-scheduler/)  
- [x] [647. 回文子串](https://leetcode-cn.com/problems/palindromic-substrings/)  
- [x] [76. 最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/)  
- [x] [312. 戳气球](https://leetcode-cn.com/problems/burst-balloons/)  

# 高级动态规划
- [x] [300. 最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)
- [x] [91. 解码方法](https://leetcode-cn.com/problems/decode-ways/)
- [x] [32. 最长有效括号](https://leetcode-cn.com/problems/longest-valid-parentheses/)
- [x] [85. 最大矩形](https://leetcode-cn.com/problems/maximal-rectangle/)
- [x] [115. 不同的子序列](https://leetcode-cn.com/problems/distinct-subsequences/)
- [x] [818. 赛车](https://leetcode-cn.com/problems/race-car/)


# 贪心算法
贪心算法与动态规划的不同在于它对每个子问题的解决方案都做出选择，不能回退。
动态规划则会保存以前的运算结果，并根据以前的结果对当前进行选择，有回退功能。

## 题目
- [x] [860. 柠檬水找零](https://leetcode-cn.com/problems/lemonade-change/description/)  
- [x] [455. 分发饼干](https://leetcode-cn.com/problems/assign-cookies/description/)  
- [x] [874. 模拟行走机器人](https://leetcode-cn.com/problems/walking-robot-simulation/description/)  
- [x] [55. 跳跃游戏](https://leetcode-cn.com/problems/jump-game/)  
- [x] [45. 跳跃游戏 II](https://leetcode-cn.com/problems/jump-game-ii/)


# 递归
```python
def recursion(level, param1, param2, ...): 
    # recursion terminator 
    if level > MAX_LEVEL: 
       process_result 
       return 

    # process logic in current level 
    process(level, data...) 

    # drill down 
    self.recursion(level + 1, p1, ...) 

    # reverse the current level status if needed
```

## 题目
- [x] [22. 括号生成](https://leetcode-cn.com/problems/generate-parentheses/)  
- [x] [70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)  
- [x] [226. 翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/description/)  
- [x] [98. 验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/)  
- [x] [104. 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)  
- [x] [111. 二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)  
- [x] [297. 二叉树的序列化与反序列化](https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/)  
- [x] [236. 二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)  
- [x] [105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)  
- [x] [77. 组合](https://leetcode-cn.com/problems/combinations/)  
- [x] [46. 全排列](https://leetcode-cn.com/problems/permutations/)  
- [x] [47. 全排列 II](https://leetcode-cn.com/problems/permutations-ii/)  、


# 最大公约数
```cpp
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
```


# 最小公倍数
```cpp
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
```


# 试除法判定质数
```cpp
bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}
```


# 试除法分解质因数
```cpp
void divide(int x) {
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0) {
            int s = 0;
            while (x % i == 0) x /= i, s ++ ;
            cout << i << ' ' << s << endl;
        }
    if (x > 1) cout << x << ' ' << 1 << endl;
    cout << endl;
}
```


# 朴素筛法求素数
```cpp
int primes[N], cnt;     // primes[]存储所有素数
bool st[N];         // st[x]存储x是否被筛掉

void get_primes(int n) {
    for (int i = 2; i <= n; i ++ ) {
        if (st[i]) continue;
        primes[cnt ++ ] = i;
        for (int j = i + i; j <= n; j += i)
            st[j] = true;
    }
}
```


# 线性筛法求素数
```cpp
int primes[N], cnt;     // primes[]存储所有素数
bool st[N];         // st[x]存储x是否被筛掉

void get_primes(int n) {
    for (int i = 2; i <= n; i ++ ) {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ ) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}
```


# 试除法求所有约数
```cpp
vector<int> get_divisors(int x) {
    vector<int> res;
    for (int i = 1; i <= x / i; i ++ )
        if (x % i == 0) {
            res.push_back(i);
            if (i != x / i) res.push_back(x / i);
        }
    sort(res.begin(), res.end());
    return res;
}
```


# 约数个数和约数之和
如果 `N = p1^c1 * p2^c2 * ... *pk^ck`
约数个数： `(c1 + 1) * (c2 + 1) * ... * (ck + 1)`
约数之和： `(p1^0 + p1^1 + ... + p1^c1) * ... * (pk^0 + pk^1 + ... + pk^ck)`


# 欧几里得算法
求两个正整数的最大公约数，时间复杂度 O(logn)O(logn)。
```cpp
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
```


# 求欧拉函数
```cpp
int phi(int x) {
    int res = x;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0) {
            res = res / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    if (x > 1) res = res / x * (x - 1);

    return res;
}
```


# 筛法求欧拉函数
```cpp
int primes[N], cnt;     // primes[]存储所有素数
int euler[N];           // 存储每个数的欧拉函数
bool st[N];         // st[x]存储x是否被筛掉

void get_eulers(int n)
{
    euler[1] = 1;
    for (int i = 2; i <= n; i ++ ) {
        if (!st[i]) {
            primes[cnt ++ ] = i;
            euler[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j ++ ) {
            int t = primes[j] * i;
            st[t] = true;
            if (i % primes[j] == 0) {
                euler[t] = euler[i] * primes[j];
                break;
            }
            euler[t] = euler[i] * (primes[j] - 1);
        }
    }
}
```


# 快速幂
求 `m^k mod p`，时间复杂度 `O(logk)`。
```cpp
int qmi(int m, int k, int p) {
    int res = 1 % p, t = m;
    while (k) {
        if (k&1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}
```


# 扩展欧几里得算法
> 裴蜀定理：若 a,ba,b 是整数,且 (a,b)=d(a,b)=d，那么对于任意的整数 x,y,ax+byx,y,ax+by 都一定是 dd 的倍数，特别地，一定存在整数 x,yx,y，使 ax+by=dax+by=d 成立。
扩展欧几里得算法可以在 O(logn)O(logn) 的时间复杂度内求出系数 x,yx,y。
```cpp
// 求x, y，使得ax + by = gcd(a, b)
int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1; y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a/b) * x;
    return d;
}
```


# 高斯消元
```cpp
// a[N][N]是增广矩阵
int gauss() {
    int c, r;
    for (c = 0, r = 0; c < n; c ++ ) {
        int t = r;
        for (int i = r; i < n; i ++ )   // 找到绝对值最大的行
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;

        if (fabs(a[t][c]) < eps) continue;

        for (int i = c; i <= n; i ++ ) swap(a[t][i], a[r][i]);      // 将绝对值最大的行换到最顶端
        for (int i = n; i >= c; i -- ) a[r][i] /= a[r][c];      // 将当前行的首位变成1
        for (int i = r + 1; i < n; i ++ )       // 用当前行将下面所有的列消成0
            if (fabs(a[i][c]) > eps)
                for (int j = n; j >= c; j -- )
                    a[i][j] -= a[r][j] * a[i][c];

        r ++ ;
    }

    if (r < n) {
        for (int i = r; i < n; i ++ )
            if (fabs(a[i][n]) > eps)
                return 2; // 无解
        return 1; // 有无穷多组解
    }

    for (int i = n - 1; i >= 0; i -- )
        for (int j = i + 1; j < n; j ++ )
            a[i][n] -= a[i][j] * a[j][n];

    return 0; // 有唯一解
}
```


# 求组合数
## 递归法求组合数
```cpp
// c[a][b] 表示从a个苹果中选b个的方案数
for (int i = 0; i < N; i ++ )
    for (int j = 0; j <= i; j ++ )
        if (!j) c[i][j] = 1;
        else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
```

## 通过预处理逆元的方式求组合数
首先预处理出所有阶乘取模的余数fact[N]，以及所有阶乘取模的逆元infact[N]
如果取模的数是质数，可以用费马小定理求逆元
```cpp
int qmi(int a, int k, int p) {   // 快速幂模板
    int res = 1;
    while (k) {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

// 预处理阶乘的余数和阶乘逆元的余数
fact[0] = infact[0] = 1;
for (int i = 1; i < N; i ++ ) {
    fact[i] = (LL)fact[i - 1] * i % mod;
    infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
}
```

## Lucas定理 
若p是质数，则对于任意整数 `1 <= m <= n`，有：
    `C(n, m) = C(n % p, m % p) * C(n / p, m / p) (mod p)`
```cpp
int qmi(int a, int k, int p) { // 快速幂模板
    int res = 1 % p;
    while (k) {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

int C(int a, int b, int p) { // 通过定理求组合数C(a, b)
    if (a < b) return 0;

    LL x = 1, y = 1;  // x是分子，y是分母
    for (int i = a, j = 1; j <= b; i --, j ++ ) {
        x = (LL)x * i % p;
        y = (LL) y * j % p;
    }

    return x * (LL)qmi(y, p - 2, p) % p;
}

int lucas(LL a, LL b, int p) {
    if (a < p && b < p) return C(a, b, p);
    return (LL)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}
```

## 分解质因数法求组合数
当我们需要求出组合数的真实值，而非对某个数的余数时，分解质因数的方式比较好用：
1. 筛法求出范围内的所有质数
2. 通过 C(a, b) = a! / b! / (a - b)! 这个公式求出每个质因子的次数。 n! 中p的次数是 n / p + n / p^2 + n / p^3 + ...
3. 用高精度乘法将所有质因子相乘

```cpp
int primes[N], cnt;     // 存储所有质数
int sum[N];     // 存储每个质数的次数
bool st[N];     // 存储每个数是否已被筛掉


void get_primes(int n) {     // 线性筛法求素数
    for (int i = 2; i <= n; i ++ ) {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ ) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}


int get(int n, int p) {      // 求n！中的次数
    int res = 0;
    while (n) {
        res += n / p;
        n /= p;
    }
    return res;
}


vector<int> mul(vector<int> a, int b) {      // 高精度乘低精度模板
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i ++ ) {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }

    while (t) {
        c.push_back(t % 10);
        t /= 10;
    }

    return c;
}

get_primes(a);  // 预处理范围内的所有质数

for (int i = 0; i < cnt; i ++ ) {    // 求每个质因数的次数
    int p = primes[i];
    sum[i] = get(a, p) - get(b, p) - get(a - b, p);
}

vector<int> res;
res.push_back(1);

for (int i = 0; i < cnt; i ++ )     // 用高精度乘法将所有质因子相乘
    for (int j = 0; j < sum[i]; j ++ )
        res = mul(res, primes[i]);
```


# 排序

## 题目
- [x] [1122. 数组的相对排序](https://leetcode-cn.com/problems/relative-sort-array/)
- [x] [242. 有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/)
- [x] [56. 合并区间](https://leetcode-cn.com/problems/merge-intervals/)
- [x] [493. 翻转对](https://leetcode-cn.com/problems/reverse-pairs/)  


# 其他题目
- [x] [146. LRU缓存机制](https://leetcode-cn.com/problems/lru-cache/#/)



# 经典习题
爬楼梯、硬币兑换  
括号匹配、括号生成
直方图最大面积、滑动窗口  
二叉树遍历、分层输出树、判断二叉排序树  
股票买卖、打家劫舍
字符串编辑距离、最长上升子序列、最长公共子序列  
异位词（判断和归类）、回文串（最大回文串）
regex和通配符匹配  
N皇后  
高级数据结构（Trie、BloomFilter、LRU cache、etc）


# references
[数据结构脑图](https://naotu.baidu.com/file/b832f043e2ead159d584cca4efb19703?token=7a6a56eb2630548c)  
[算法脑图](https://naotu.baidu.com/file/0a53d3a5343bd86375f348b2831d3610?token=5ab1de1c90d5f3ec)  
[Know Thy Complexities!](https://www.bigocheatsheet.com/)  
[数据结构与算法之美 代码](https://github.com/wangzheng0822/algo)  
[https://www.acwing.com/blog/content/404/](https://www.acwing.com/blog/content/404/)  
[https://www.acwing.com/blog/content/406/](https://www.acwing.com/blog/content/406/)  
[https://www.acwing.com/blog/content/405/](https://www.acwing.com/blog/content/405/)  
[https://www.acwing.com/blog/content/277/](https://www.acwing.com/blog/content/277/)  
