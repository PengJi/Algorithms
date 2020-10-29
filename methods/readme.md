# 常用方法

# 双指针

# 滑动窗口
- [x] [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)
- [x] [76. 最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/)
- [x] [438. 找到字符串中所有字母异位词](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/)
- [ ] [567. 字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/)

# 单调栈

# 并查集
用于组团、配对问题

基本操作：  
* makeSet(s)：建立一个新的并查集，其中包含 s 个单元素集合。
* unionSet(x, y)：把元素 x 和元素 y 所在的集合合并，要求 x 和 y 所在的集合不相交，如果相交则不合并。
* find(x)：找到元素 x 所在的集合的代表，该操作也可以用于判断两个元素是否位于同一个集合，只要将它们各自的代表比较一下就可以了。

##  题目 
- [x] [547. 朋友圈](https://leetcode-cn.com/problems/friend-circles/)
- [x] [130. 被围绕的区域](https://leetcode-cn.com/problems/surrounded-regions/)
- [x] [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/) 

# LRU

# 题目
- [x] [146. LRU缓存机制](https://leetcode-cn.com/problems/lru-cache/#/)