# 回溯法
回溯法采用试错的思想，它尝试分步的去解决一个问题。在分步解决问题的过程中，当它通过尝试发现现有的分步答案不能得到有效的正确的解答的时候，它将取消上一步甚至是上几步的计算，再通过其它的可能的分步解答再次尝试寻找问题的答案。  

回溯法通常用最简单的递归方法来实现，在反复重复上述的步骤后可能出现两种情况：
1. 找到一个可能存在的正确的答案
2. 在尝试了所有可能的分步方法后宣告该问题没有答案

在最坏的情况下，回溯法会导致一次复杂度为指数时间的计算。

# 题目
[70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)  
[22. 括号生成](https://leetcode-cn.com/problems/generate-parentheses/)  
[51. N皇后](https://leetcode-cn.com/problems/n-queens/)  
[36. 有效的数独](https://leetcode-cn.com/problems/valid-sudoku/description/)  
[37. 解数独](https://leetcode-cn.com/problems/sudoku-solver/#/description)
