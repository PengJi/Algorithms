/**
 * 2644. 找出可整除性得分最大的整数
 * https://leetcode.cn/problems/find-the-maximum-divisibility-score/
*/
class Solution {
public:
    // 暴力枚举
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int r = -1, ans = INT_MAX;

        for (int d : divisors) {
            int cnt = 0;
            for (int x : nums)
                if (x % d == 0)
                    cnt++;

            if (r < cnt || r == cnt && ans > d) {
                r = cnt;
                ans = d;
            }
        }

        return ans;
    }
};
