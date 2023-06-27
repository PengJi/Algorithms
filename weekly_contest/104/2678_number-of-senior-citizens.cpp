/**
 * 2678. 老人的数目
 * https://leetcode.cn/problems/number-of-senior-citizens/
*/
class Solution {
public:
    // 模拟
    int countSeniors(vector<string>& details) {
        int ans = 0;

        for (const auto &s : details)
            if ((s[11] - '0') * 10 + s[12] - '0' > 60)
                ans++;

        return ans;
    }
};
