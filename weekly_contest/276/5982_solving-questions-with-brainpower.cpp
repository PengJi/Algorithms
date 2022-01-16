/**
 * 5982. 解决智力问题
 * https://leetcode-cn.com/problems/solving-questions-with-brainpower/
 */

class Solution {
public:
    long long mostPoints(vector<vector<int>> &questions) {
        int n = questions.size();
        vector<long long> f(n+1);
        for(int i = 0; i < n; i++) {
            f[i+1] = max(f[i+1], f[i]);  // 跳过
            auto q = questions[i];
            int j = min(i + q[1] + 1, n);
            f[j] = max(f[j], f[i] + q[0]);  // 不跳过
        }
        return f[n];
    }
};
