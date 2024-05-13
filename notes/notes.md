# 排序
## 快速排序
```cpp
int sort(vector<int>& arr, int left, int right) {
    int pivot = arr[left];

    while (left < right) {
        while (left < right && pivot <= arr[right]) right--;  // 升序
        arr[left] = arr[right];

        while (left < right && pivot >= arr[left]) left++;  // 升序
        arr[right] = arr[left];
    }

    arr[left] = pivot;
    return left;
}

void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = sort(arr, left, right);  // mid 位置的元素确定
        quickSort(arr, left, mid - 1);
        quickSort(arr, mid + 1, right);
    }
}
```

## 归并排序
```cpp
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> tmp(right - left + 1);
    int i = left, j = mid+1, k = 0;

    while(i <= mid && j <= right) {
        tmp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];  // 升序
    }

    while(i <= mid) tmp[k++] = arr[i++];
    while(j <= right) tmp[k++] = arr[j++];

    for(int p = 0; p < tmp.size(); p++) {
        arr[left+p] = tmp[p];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if(left >= right) return;
    int mid = (left + right) >> 1;  // (left+right)/2

    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}
```

# 二分查找
```cpp
vector<int> arr(n);
int l = 0, r = n - 1;
int bsearch(int l, int r, int target) {
    while (l < r) {
        int mid = l + r >> 1;
        if (arr[mid] < target) l = mid + 1;  // 注意：这里为 mid+1
        else r = mid;  // 注意
    }
    return l;
}
```

# 字符串

6. Z 字形变换
https://leetcode-cn.com/problems/zigzag-conversion/

8. 字符串转换整数 (atoi)
https://leetcode-cn.com/problems/string-to-integer-atoi/

14. 最长公共前缀
https://leetcode-cn.com/problems/longest-common-prefix/

28. 找出字符串中第一个匹配项的下标
https://leetcode-cn.com/problems/implement-strstr/

43. 字符串相乘
https://leetcode-cn.com/problems/multiply-strings/

49. 字母异位词分组
https://leetcode-cn.com/problems/group-anagrams/

58. 最后一个单词的长度
https://leetcode-cn.com/problems/length-of-last-word/

151. 反转字符串中的单词
https://leetcode-cn.com/problems/reverse-words-in-a-string/

165. 比较版本号
https://leetcode-cn.com/problems/compare-version-numbers/

171. Excel 表列序号
https://leetcode-cn.com/problems/excel-sheet-column-number/

205. 同构字符串
https://leetcode-cn.com/problems/isomorphic-strings/

387. 字符串中的第一个唯一字符
https://leetcode-cn.com/problems/first-unique-character-in-a-string/

415. 字符串相加
https://leetcode-cn.com/problems/add-strings/

344. 反转字符串
https://leetcode-cn.com/problems/reverse-string/

541. 反转字符串 II
https://leetcode-cn.com/problems/reverse-string-ii/

557. 反转字符串中的单词 III
https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/

647. 回文子串
https://leetcode-cn.com/problems/palindromic-substrings/

709. 转换成小写字母
https://leetcode-cn.com/problems/to-lower-case/

771. 宝石与石头
https://leetcode-cn.com/problems/jewels-and-stones/

917. 仅仅反转字母
https://leetcode-cn.com/problems/reverse-only-letters/

30. 串联所有单词的子串
https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/

60. 排列序列
https://leetcode-cn.com/problems/permutation-sequence/

68. 文本左右对齐
https://leetcode-cn.com/problems/text-justification/    

214. 最短回文串
https://leetcode-cn.com/problems/shortest-palindrome/


# 链表

19. 删除链表的倒数第N个节点
https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/

21. 合并两个有序链表
https://leetcode-cn.com/problems/merge-two-sorted-lists/

23. 合并K个升序链表
https://leetcode-cn.com/problems/merge-k-sorted-lists/

24. 两两交换链表中的节点
https://leetcode-cn.com/problems/swap-nodes-in-pairs/

61. 旋转链表
https://leetcode-cn.com/problems/rotate-list/

82. 删除排序链表中的重复元素 II
https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/

83. 删除排序链表中的重复元素
https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/

86. 分隔链表
https://leetcode-cn.com/problems/partition-list/

114. 二叉树展开为链表
https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/

138. 复制带随机指针的链表
https://leetcode-cn.com/problems/copy-list-with-random-pointer/

141. 环形链表
https://leetcode-cn.com/problems/linked-list-cycle/

160. 相交链表
https://leetcode-cn.com/problems/intersection-of-two-linked-lists/

203. 移除链表元素
https://leetcode-cn.com/problems/remove-linked-list-elements/

206. 反转链表
https://leetcode-cn.com/problems/reverse-linked-list/

25. K 个一组翻转链表
https://leetcode-cn.com/problems/reverse-nodes-in-k-group/

234. 回文链表
https://leetcode-cn.com/problems/palindrome-linked-list/

237. 删除链表中的节点
https://leetcode-cn.com/problems/delete-node-in-a-linked-list/

146. LRU缓存机制
https://leetcode-cn.com/problems/lru-cache/


# 二叉树
144. 二叉树的前序遍历
https://leetcode-cn.com/problems/binary-tree-preorder-traversal/

94. 二叉树的中序遍历
https://leetcode-cn.com/problems/binary-tree-inorder-traversal/

145. 二叉树的后序遍历
https://leetcode-cn.com/problems/binary-tree-postorder-traversal/

102. 二叉树的层序遍历
https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

107. 二叉树的层次遍历 II
https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/

515. 在每个树行中找最大值
https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/

103. 二叉树的锯齿形层序遍历
https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/

429. N叉树的层序遍历
https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/

589. N叉树的前序遍历
https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/

590. N叉树的后序遍历
https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/

199. 二叉树的右视图
https://leetcode-cn.com/problems/binary-tree-right-side-view/

173. 二叉搜索树迭代器
https://leetcode-cn.com/problems/binary-search-tree-iterator/

230. 二叉搜索树中第K小的元素
https://leetcode.cn/problems/kth-smallest-element-in-a-bst/

235. 二叉搜索树的最近公共祖先
https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/

236. 二叉树的最近公共祖先
https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/


98. 验证二叉搜索树
https://leetcode-cn.com/problems/validate-binary-search-tree/

110. 平衡二叉树
https://leetcode-cn.com/problems/balanced-binary-tree/

100. 相同的树
https://leetcode-cn.com/problems/same-tree/

572. 另一个树的子树
https://leetcode-cn.com/problems/subtree-of-another-tree/

226. 翻转二叉树
https://leetcode-cn.com/problems/invert-binary-tree/

872. 叶子相似的树
https://leetcode-cn.com/problems/leaf-similar-trees/

95. 不同的二叉搜索树 II
https://leetcode-cn.com/problems/unique-binary-search-trees-ii/


104. 二叉树的最大深度
https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/

111. 二叉树的最小深度
https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/

543. 二叉树的直径
https://leetcode-cn.com/problems/diameter-of-binary-tree/

563. 二叉树的坡度
https://leetcode-cn.com/problems/binary-tree-tilt/

662. 二叉树最大宽度
https://leetcode-cn.com/problems/maximum-width-of-binary-tree/


105. 从前序与中序遍历序列构造二叉树
https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

106. 从中序与后序遍历序列构造二叉树
https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

116. 填充每个节点的下一个右侧节点指针
https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/

117. 填充每个节点的下一个右侧节点指针 II
https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/

297. 二叉树的序列化与反序列化
https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/

654. 最大二叉树
https://leetcode-cn.com/problems/maximum-binary-tree/

617. 合并二叉树
https://leetcode-cn.com/problems/merge-two-binary-trees/

99. 恢复二叉搜索树
https://leetcode-cn.com/problems/recover-binary-search-tree/

109. 有序链表转换二叉搜索树
https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/


112. 路径总和
https://leetcode-cn.com/problems/path-sum/

113. 路径总和 II
https://leetcode-cn.com/problems/path-sum-ii/

437. 路径总和 III
https://leetcode.cn/problems/path-sum-iii/

124. 二叉树中的最大路径和
https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/

129. 求根节点到叶节点数字之和
https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/

257. 二叉树的所有路径
https://leetcode-cn.com/problems/binary-tree-paths/

211. 添加与搜索单词 - 数据结构设计
https://leetcode-cn.com/problems/design-add-and-search-words-data-structure/

222. 完全二叉树的节点个数
https://leetcode-cn.com/problems/count-complete-tree-nodes/


# 技巧

1. 两数之和
https://leetcode-cn.com/problems/two-sum/

167. 两数之和 II - 输入有序数组
https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/

15. 三数之和
https://leetcode-cn.com/problems/3sum/

18. 四数之和
https://leetcode-cn.com/problems/4sum/

42. 接雨水
https://leetcode-cn.com/problems/trapping-rain-water/

11. 盛最多水的容器
https://leetcode-cn.com/problems/container-with-most-water/

84. 柱状图中最大的矩形
https://leetcode-cn.com/problems/largest-rectangle-in-histogram/

85. 最大矩形
https://leetcode-cn.com/problems/maximal-rectangle/

560. 和为K的子数组
https://leetcode-cn.com/problems/subarray-sum-equals-k/

974. 和可被 K 整除的子数组
https://leetcode-cn.com/problems/subarray-sums-divisible-by-k/

209. 长度最小的子数组
https://leetcode-cn.com/problems/minimum-size-subarray-sum/

239. 滑动窗口最大值
https://leetcode-cn.com/problems/sliding-window-maximum/

3. 无重复字符的最长子串
https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

26. 删除排序数组中的重复项
https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/

80. 删除排序数组中的重复项 II
https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/

125. 验证回文串
https://leetcode-cn.com/problems/valid-palindrome/

228. 汇总区间
https://leetcode-cn.com/problems/summary-ranges/

264. 丑数 II
https://leetcode-cn.com/problems/ugly-number-ii/

283. 移动零
https://leetcode-cn.com/problems/move-zeroes/

284. 顶端迭代器
https://leetcode-cn.com/problems/peeking-iterator/

295. 数据流的中位数
https://leetcode-cn.com/problems/find-median-from-data-stream/

303. 区域和检索 - 数组不可变
https://leetcode-cn.com/problems/range-sum-query-immutable/

304. 二维区域和检索 - 矩阵不可变
https://leetcode-cn.com/problems/range-sum-query-2d-immutable/


438. 找到字符串中所有字母异位词
https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/

567. 字符串的排列
https://leetcode-cn.com/problems/permutation-in-string/

76. 最小覆盖子串
https://leetcode-cn.com/problems/minimum-window-substring/


503. 下一个更大元素 II
https://leetcode.cn/problems/next-greater-element-ii/description/

581. 最短无序连续子数组
https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/

674. 最长连续递增序列
https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/

680. 验证回文字符串 Ⅱ
https://leetcode-cn.com/problems/valid-palindrome-ii/

739. 每日温度
https://leetcode-cn.com/problems/daily-temperatures/

65. 有效数字
https://leetcode-cn.com/problems/valid-number/

547. 省份数量
https://leetcode-cn.com/problems/number-of-provinces/


# DP
5. 最长回文子串
https://leetcode-cn.com/problems/longest-palindromic-substring/

70. 爬楼梯
https://leetcode-cn.com/problems/climbing-stairs/

10. 正则表达式匹配
https://leetcode-cn.com/problems/regular-expression-matching/

32. 最长有效括号
https://leetcode-cn.com/problems/longest-valid-parentheses/

44. 通配符匹配
https://leetcode-cn.com/problems/wildcard-matching/

121. 买卖股票的最佳时机
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/

122. 买卖股票的最佳时机 II
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/

123. 买卖股票的最佳时机 III
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/

309. 最佳买卖股票时机含冷冻期
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

188. 买卖股票的最佳时机 IV
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/

714. 买卖股票的最佳时机含手续费
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

198. 打家劫舍
https://leetcode-cn.com/problems/house-robber/

213. 打家劫舍 II
https://leetcode-cn.com/problems/house-robber-ii/

337. 打家劫舍 III
https://leetcode-cn.com/problems/house-robber-iii/

322. 零钱兑换
https://leetcode-cn.com/problems/coin-change/

518. 零钱兑换 II
https://leetcode-cn.com/problems/coin-change-2/

1143. 最长公共子序列
https://leetcode-cn.com/problems/longest-common-subsequence/

300. 最长递增子序列
https://leetcode.cn/problems/longest-increasing-subsequence/


221. 最大正方形
https://leetcode-cn.com/problems/maximal-square/

118. 杨辉三角
https://leetcode-cn.com/problems/pascals-triangle/

45. 跳跃游戏 II
https://leetcode-cn.com/problems/jump-game-ii/

53. 最大子序和
https://leetcode-cn.com/problems/maximum-subarray/

62. 不同路径
https://leetcode-cn.com/problems/unique-paths/

63. 不同路径 II
https://leetcode-cn.com/problems/unique-paths-ii/

64. 最小路径和
https://leetcode-cn.com/problems/minimum-path-sum/

72. 编辑距离
https://leetcode-cn.com/problems/edit-distance/

87. 扰乱字符串
https://leetcode-cn.com/problems/scramble-string/

91. 解码方法
https://leetcode-cn.com/problems/decode-ways/

96. 不同的二叉搜索树
https://leetcode-cn.com/problems/unique-binary-search-trees/

97. 交错字符串
https://leetcode-cn.com/problems/interleaving-string/

115. 不同的子序列
https://leetcode-cn.com/problems/distinct-subsequences/

120. 三角形最小路径和
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

131. 分割回文串
https://leetcode-cn.com/problems/palindrome-partitioning/

139. 单词拆分
https://leetcode-cn.com/problems/word-break/

140. 单词拆分 II
https://leetcode-cn.com/problems/word-break-ii/

152. 乘积最大子数组
https://leetcode-cn.com/problems/maximum-product-subarray/

174. 地下城游戏
https://leetcode-cn.com/problems/dungeon-game/

279. 完全平方数
https://leetcode-cn.com/problems/perfect-squares/

312. 戳气球
https://leetcode-cn.com/problems/burst-balloons/

363. 矩形区域不超过 K 的最大数值和
https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/

403. 青蛙过河
https://leetcode-cn.com/problems/frog-jump/

410. 分割数组的最大值
https://leetcode.cn/problems/split-array-largest-sum/

416. 分割等和子集
https://leetcode-cn.com/problems/partition-equal-subset-sum/

494. 目标和
https://leetcode-cn.com/problems/target-sum/

552. 学生出勤记录 II
https://leetcode-cn.com/problems/student-attendance-record-ii/

621. 任务调度器
https://leetcode-cn.com/problems/task-scheduler/

818. 赛车
https://leetcode-cn.com/problems/race-car/

837. 新21点
https://leetcode-cn.com/problems/new-21-game/

980. 不同路径 III
https://leetcode-cn.com/problems/unique-paths-iii/


# 模拟
54. 螺旋矩阵
https://leetcode-cn.com/problems/spiral-matrix/

59. 螺旋矩阵 II
https://leetcode-cn.com/problems/spiral-matrix-ii/
