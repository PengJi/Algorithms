# 模拟
- [x] [15. 三数之和](https://leetcode-cn.com/problems/3sum/)  
- [x] [26. 删除排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)  
- [x] [189. 旋转数组](https://leetcode-cn.com/problems/rotate-array/)  
- [x] [88. 合并两个有序数组](https://leetcode-cn.com/problems/merge-sorted-array/)  
- [x] [66. 加一](https://leetcode-cn.com/problems/plus-one/)  
- [x] [36. 有效的数独](https://leetcode-cn.com/problems/valid-sudoku/description/) 

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


# 哈希表
哈希表（Hash table 也叫散列表，是根据关键码值（ Key value）而直接进行访问的数据结构 。
它通过把关键码值映射到表中一个位置来访问记录，以加快查找的
速度。
这个映射函数叫作散列函数（ Hash Function 存放记录的数组叫作哈希表（或散列表 ）。

## 题目
- [x] [1. 两数之和](https://leetcode-cn.com/problems/two-sum/description/)  
- [x] [49. 字母异位词分组](https://leetcode-cn.com/problems/group-anagrams/)  
- [x] [242. 有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/description/)  


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
 

# 队列

## 题目
- [x] [239. 滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/) 


# 栈

## 题目
- [x] [84. 柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)


# 树
## 二叉树结构体
```python
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
```

```c++
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}
```

```java
public class TreeNode {
    public int val;
    public TreeNode left, right;
    public TreeNode(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
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


# 链表

## 题目
- [x] [206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/)  
- [x] [24. 两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/)  
- [x] [141. 环形链表](https://leetcode.cn/problems/linked-list-cycle/)  
- [x] [142. 环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/)  
- [x] [25. K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/)
- [x] [21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)  


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


# 常用方法

## 双指针
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

## 滑动窗口
- [x] [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)
- [x] [76. 最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/)
- [x] [438. 找到字符串中所有字母异位词](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/)
- [x] [567. 字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/)

## 单调栈

## 并查集
用于组团、配对问题

基本操作：  
* makeSet(s)：建立一个新的并查集，其中包含 s 个单元素集合。
* unionSet(x, y)：把元素 x 和元素 y 所在的集合合并，要求 x 和 y 所在的集合不相交，如果相交则不合并。
* find(x)：找到元素 x 所在的集合的代表，该操作也可以用于判断两个元素是否位于同一个集合，只要将它们各自的代表比较一下就可以了。

- [x] [547. 朋友圈](https://leetcode-cn.com/problems/friend-circles/)
- [x] [130. 被围绕的区域](https://leetcode-cn.com/problems/surrounded-regions/)
- [x] [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/) 

## LRU

- [x] [146. LRU缓存机制](https://leetcode-cn.com/problems/lru-cache/#/)


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
- [x] [47. 全排列 II](https://leetcode-cn.com/problems/permutations-ii/)  


# 排序

## 题目
- [x] [1122. 数组的相对排序](https://leetcode-cn.com/problems/relative-sort-array/)
- [x] [242. 有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/)
- [x] [56. 合并区间](https://leetcode-cn.com/problems/merge-intervals/)
- [x] [493. 翻转对](https://leetcode-cn.com/problems/reverse-pairs/)  


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
