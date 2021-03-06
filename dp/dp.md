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


# 题目
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
