/**
 * 2901. 最长相邻不相等子序列 II
 * https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-ii/description/
*/
class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words,
        vector<int>& groups
    ) {
        vector<int> f(n, 1), g(n, -1);

        int res = 1, p = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[j] == groups[i])
                    continue;

                if (words[i].size() != words[j].size())
                    continue;

                int cnt = 0;
                for (int k = 0; k < words[i].size(); k++)
                    if (words[i][k] != words[j][k])
                        ++cnt;

                if (cnt != 1)
                    continue;

                if (f[i] < f[j] + 1) {
                    f[i] = f[j] + 1;
                    g[i] = j;
                }
            }

            if (res < f[i]) {
                res = f[i];
                p = i;
            }
        }

        vector<string> ans;
        while (p != -1) {
            ans.push_back(words[p]);
            p = g[p];
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
