/**
 * 2746. 字符串连接删减字母
 * https://leetcode.cn/problems/decremental-string-concatenation/description/
*/

const int N = 26;

class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        const int n = words.size();

        int f[N][N], g[N][N];

        memset(f, 0x3f, sizeof(f));
        memset(g, 0x3f, sizeof(g));

        f[words[0].front() - 'a'][words[0].back() - 'a'] = words[0].size();

        for (int i = 1; i < n; i++) {
            int len = words[i].size();
            int s = words[i].front() - 'a';
            int e = words[i].back() - 'a';

            for (int j = 0; j < 26; j++)
                for (int k = 0; k < 26; k++) {
                    g[j][e] = min(g[j][e], f[j][k] + len - (s == k));
                    g[s][k] = min(g[s][k], f[j][k] + len - (e == j));
                }

            memcpy(f, g, sizeof(f));
            memset(g, 0x3f, sizeof(g));
        }

        int ans = INT_MAX;
        for (int j = 0; j < 26; j++)
            for (int k = 0; k < 26; k++)
                ans = min(ans, f[j][k]);

        return ans;
    }
};
