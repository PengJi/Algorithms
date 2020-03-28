# 并查集
用于组团、配对问题

基本操作：  
* makeSet(s)：建立一个新的并查集，其中包含 s 个单元素集合。
* unionSet(x, y)：把元素 x 和元素 y 所在的集合合并，要求 x 和 y 所在的集合不相交，如果相交则不合并。
* find(x)：找到元素 x 所在的集合的代表，该操作也可以用于判断两个元素是否位于同一个集合，只要将它们各自的代表比较一下就可以了。

# 题目 
[547. 朋友圈](https://leetcode-cn.com/problems/friend-circles/)  
[200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)  
[130. 被围绕的区域](https://leetcode-cn.com/problems/surrounded-regions/)

