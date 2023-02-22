/**
 * 2515. 到目标字符串的最短距离
 * https://leetcode.cn/problems/shortest-distance-to-target-string-in-a-circular-array/description/
*/

class Solution {
public:
    // 分别正序和倒序遍历
    int closetTarget(vector<string>& words, string target, int startIndex) {
        const int n = words.size();

        int ans = n;
        for (int i = 0; i < n; i++)
            if (words[i] == target) {
                ans = min(ans, abs(i - startIndex));
                ans = min(ans, n - abs(i - startIndex));
            }

        if (ans == n)
            ans = -1;

        return ans;
    }
};
