/**
 * 14. 最长公共前缀
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * https://leetcode-cn.com/problems/longest-common-prefix/
 */

class Solution {
public:
    // 遍历，遍历每个字符串
    // 时间复杂度：O(n)，n为所有字符串长度之和
    // 空间复杂度：O(1)
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if(len == 0) return "";

        string ans = strs[0];
        for(int i = 1; i < len; i++) {
            int j = 0;
            for(; j < ans.size() && j < strs[i].size(); j++) {
                if(ans[j] != strs[i][j]) break;
            }
            ans  = ans.substr(0, j);
            if(ans.equal("")) return ans;
        }

        return ans;
    }

    // 排序
    // https://leetcode-cn.com/problems/longest-common-prefix/solution/jin-bi-jiao-liang-ge-zi-fu-chuan-14zui-chang-gong-/
    // 时间复杂度：O(nlogn + m)，n为字符串数组的长度，m为最短字符串的长度
    // 空间复杂度：O(1)
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(strs.empty())  return "";

        // 排序
        sort(strs.begin(), strs.end());

        // 比较最短和最长的字符串
        for(int i = 0; i < min(strs[0].size(),strs[n-1].size()); ++i){
            if(strs[0][i] != strs[n-1][i]) return strs[0].substr(0, i);
        }

        return strs[0];
    }
};
