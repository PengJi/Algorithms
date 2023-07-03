/**
 * 2682. 找出转圈游戏输家
 * https://leetcode.cn/problems/find-the-losers-of-the-circular-game/
*/
class Solution {
public:
    // 模拟
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> seen(n, false);
        int c = 0, r = 1;

        while (!seen[c]) {
            seen[c] = true;
            c = (c + r * k) % n;
            ++r;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (!seen[i])
                ans.push_back(i + 1);

        return ans;
    }
};
