/**
 * 139. 单词拆分
 * https://leetcode.cn/problems/word-break/description/
 */

class Solution {
public:
    // https://leetcode.cn/problems/word-break/solutions/302471/dan-ci-chai-fen-by-leetcode-solution/
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for (auto& w : wordDict) st.insert(w);
        int n = s.size();
        vector<bool> dp(n + 1);  // dp[i] 表示字符串 sss 前 iii 个字符组成的字符串 s[0..i−1] 是否能被空格拆分成若干个字典中出现的单词
        dp[0] = true;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && st.count(s.substr(j, i - j))) {  // substr 需要优化
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

class Solution {
public:
    typedef unsigned long long ULL;

    // 算法同上，使用字符串哈希优化 substr
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<ULL> st;
        const int p = 131;
        int n = s.size();
        vector<bool> dp(n + 1);
        dp[0] = true;

        // 将字符串转为整数存入哈希表
        for (auto& word : wordDict) {
            ULL key = 0;
            for (auto& c : word) {
                key = key * p + c;
            }
            st.insert(key);
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j]) {  // 通过字符串哈希表判断
                    ULL key = 0;
                    for (int k = j; k < i; k++) key = key * p + s[k];

                    if (st.count(key)) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[n];
    }
};
