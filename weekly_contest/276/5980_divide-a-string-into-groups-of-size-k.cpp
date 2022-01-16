/**
 * 5980. 将字符串拆分为若干长度为 k 的组
 * https://leetcode-cn.com/problems/divide-a-string-into-groups-of-size-k/
 */

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int l = 0;
        while(l < s.size()) {
            int r = l + k - 1;
            string tmp = "";
            for(int i = l; i <= r; i++) {
                if(i >= s.size()) tmp.push_back(fill);
                else tmp.push_back(s[i]); 
            }
            res.push_back(tmp);
        }

        return res;
    }
};
