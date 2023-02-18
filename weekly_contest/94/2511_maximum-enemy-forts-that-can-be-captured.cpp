/**
 * 2511. 最多可以摧毁的敌人城堡数目
 * https://leetcode.cn/problems/maximum-enemy-forts-that-can-be-captured/description/
*/

class Solution {
private:
    int solve(const vector<int> &forts) {
        int c = INT_MIN, res = 0;

        for (int x : forts)
            if (x == 0) {
                c++;
            } else if (x == 1) {
                c = 0;
            } else {
                res = max(res, c);
                c = INT_MIN;
            }

        return res;
    }

public:
    // 分别正序和倒序遍历数组
    int captureForts(vector<int>& forts) {
        int ans = solve(forts);

        reverse(forts.begin(), forts.end());
        ans = max(ans, solve(forts));

        return ans;
    }
};
