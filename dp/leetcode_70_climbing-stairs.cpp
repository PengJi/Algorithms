/**
 * 70. 爬楼梯
 * https://leetcode-cn.com/problems/climbing-stairs/
 */

class Solution {
public:
    // 暴力法（超时）
    // 类似一棵递归树
    // 时间复杂度：O(2^n)
    // 空间复杂度：O(n)
    int climbStairs(int n) {
        return climbStair(0, n);
    }

    int climbStair(i, n){
        if(i > n) return 0;
        if(i = n) return 1;
        return climbStair(i+1, n) + climbStair(i+2, n);
    }

    // 记忆化递归（超时）
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int climbStairs(int n) {
        vector<int> memo(n);
        return climbStair(0, n);
    }

    int climbStair(i, n, vecotr<int> memo){
        if(i > n) return 0;
        if(i == n) return 1;
        if(memo[i] > 0) return memo[i];
        memo[i] = climbStair(i+1, n, memo) + climbStair(i+2, n, memo);
        return memo;
    }

    // 动态规划（自底向上）
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int climbStairs(int n) {
        if(n == 1) return 1;
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

    // 斐波那契数列
    int climbStairs(int n) {
        if(n == 1) return 1;
        int lastOne = 2;
        int lastTwo = 1;
        int lastThree;

        for(int i=3; i<=n; i++){
            lastThree = lastOne + lastTwo;
            lastTwo = lastOne;
            lastOne = lastThree;
        }

        return lastOne;
    }
};
