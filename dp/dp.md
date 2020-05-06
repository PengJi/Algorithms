# 动态规划
关键点：  
* 最优子结构 opt[n] = best_of(opt[n-1], opt[n-2], …)  
* 储存中间状态：opt[i]  
* 递推公式（美其名曰：状态转移方程或者 DP 方程）   
Fib: opt[i] = opt[n-1] + opt[n-2]   
二维路径：opt[i,j] = opt[i+1][j] + opt[i][j+1] (且判断a[i,j]是否空地）

动态规划做题步骤  
* 明确 dp(i)dp(i) 应该表示什么（二维情况：dp(i)(j)dp(i)(j)）；  
* 根据 dp(i)dp(i) 和 dp(i-1)dp(i−1) 的关系得出状态转移方程；  
* 确定初始条件，如 dp(0)dp(0)。  


# 题目
[70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)  
[120. 三角形最小路径和](https://leetcode-cn.com/problems/triangle/)  
[53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)  
[152. 乘积最大子数组](https://leetcode-cn.com/problems/maximum-product-subarray/description/)  
[322. Coin Change](https://leetcode.com/problems/coin-change/description/)  
[198. 打家劫舍](https://leetcode-cn.com/problems/house-robber/)  
[213. 打家劫舍 II](https://leetcode-cn.com/problems/house-robber-ii/description/)  
[121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/#/description)  
[122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)  
[123. 买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)  
[309. 最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)  
[188. 买卖股票的最佳时机 IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)  
[714. 买卖股票的最佳时机含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)  
[279. 完全平方数](https://leetcode-cn.com/problems/perfect-squares/)  
[72. 编辑距离](https://leetcode-cn.com/problems/edit-distance/)  
[55. 跳跃游戏](https://leetcode-cn.com/problems/jump-game/)  
[45. 跳跃游戏 II](https://leetcode-cn.com/problems/jump-game-ii/)  
[62. 不同路径](https://leetcode-cn.com/problems/unique-paths/)  
[63. 不同路径 II](https://leetcode-cn.com/problems/unique-paths-ii/)  
[980. 不同路径 III](https://leetcode-cn.com/problems/unique-paths-iii/)  
[322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/)    
[518. 零钱兑换 II](https://leetcode-cn.com/problems/coin-change-2/)  
[32. 最长有效括号](https://leetcode-cn.com/problems/longest-valid-parentheses/)   
[64. 最小路径和](https://leetcode-cn.com/problems/minimum-path-sum/)  
[91. 解码方法](https://leetcode-cn.com/problems/decode-ways/)  
[221. 最大正方形](https://leetcode-cn.com/problems/maximal-square/)  
[363. 矩形区域不超过 K 的最大数值和](https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/)  
[403. 青蛙过河](https://leetcode-cn.com/problems/frog-jump/)  
[410. 分割数组的最大值](https://leetcode-cn.com/problems/split-array-largest-sum/)  
[552. 学生出勤记录 II](https://leetcode-cn.com/problems/student-attendance-record-ii/)  
[621. 任务调度器](https://leetcode-cn.com/problems/task-scheduler/)  
[647. 回文子串](https://leetcode-cn.com/problems/palindromic-substrings/)  
[76. 最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/)  
[312. 戳气球](https://leetcode-cn.com/problems/burst-balloons/)  

# 高级动态规划
[300. 最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)
[91. 解码方法](https://leetcode-cn.com/problems/decode-ways/)
[32. 最长有效括号](https://leetcode-cn.com/problems/longest-valid-parentheses/)
[85. 最大矩形](https://leetcode-cn.com/problems/maximal-rectangle/)
[115. 不同的子序列](https://leetcode-cn.com/problems/distinct-subsequences/)
[818. 赛车](https://leetcode-cn.com/problems/race-car/)

