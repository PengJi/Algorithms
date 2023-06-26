/**
 * 2673. 使二叉树所有路径值相等的最小代价
 * https://leetcode.cn/problems/make-costs-of-paths-equal-in-a-binary-tree/
*/
class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;

        for (int i = cost.size() / 2 - 1; i >= 0; i--) {
            int l = 2 * i + 1, r = 2 * i + 2;
            ans += abs(cost[l] - cost[r]);
            cost[i] += max(cost[l], cost[r]);
        }

        return ans;
    }
};
