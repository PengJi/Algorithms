/**
 * 1930. 长度为 3 的不同回文子序列
 * https://leetcode-cn.com/problems/unique-length-3-palindromic-subsequences/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/unique-length-3-palindromic-subsequences/solution/chang-du-wei-3-de-bu-tong-hui-wen-zi-xu-21trj/
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int res = 0;
        // 枚举两侧字符
        for (char ch = 'a'; ch <= 'z'; ++ch){
            int l = 0, r = n - 1;
            // 寻找该字符第一次出现的下标
            while (l < n && s[l] != ch){
                ++l;
            }
            // 寻找该字符最后一次出现的下标
            while (r >= 0 && s[r] != ch){
                --r;
            }
            if (r - l < 2){
                // 该字符未出现，或两下标中间的子串不存在
                continue;
            }
            // 利用哈希集合统计 s[l+1..r-1] 子串的字符总数，并更新答案
            unordered_set<char> charset;
            for (int k = l + 1; k < r; ++k){
                charset.insert(s[k]);
            }
            res += charset.size();
        }
        return res;
    }
};
