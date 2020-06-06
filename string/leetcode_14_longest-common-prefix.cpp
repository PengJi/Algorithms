class Solution {
public:
    // 解法：https://leetcode-cn.com/problems/longest-common-prefix/solution/jin-bi-jiao-liang-ge-zi-fu-chuan-14zui-chang-gong-/
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(strs.empty())  return "";

        sort(strs.begin(),strs.end());

        for(int i = 0; i < min(strs[0].size(),strs[n-1].size()); ++i){
            if(strs[0][i] != strs[n-1][i]) 
                return strs[0].substr(0,i);
        }

        return strs[0];
    }
};