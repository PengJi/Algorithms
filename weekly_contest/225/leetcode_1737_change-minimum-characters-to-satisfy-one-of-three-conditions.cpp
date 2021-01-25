/**
 * 5662. 满足三条件之一需改变的最少字符数
 * https://leetcode-cn.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/
 */

class Solution {
public:
    // 前缀和 + 后缀和
    // https://leetcode-cn.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/solution/czui-jian-qian-zhui-he-hou-zhui-he-jie-f-znoc/
    int minCharacters(string a, string b) {
        vector<int> acnt(26, 0);
        vector<int> bcnt(26, 0);
        int alen = a.size(), blen = b.size();

        for(char c : a) acnt[c-'a']++;
        for(char c : b) bcnt[c-'a']++;

        int ans = INT_MAX;
        int asum = 0, bsum = 0;
        for(int i = 0; i < 25; i++) {
            asum += acnt[i];
            bsum += bcnt[i];
            ans = min(min(ans, alen-acnt[i]+blen-bcnt[i]), min(alen-asum+bsum, blen-bsum+asum));
        }
        ans = min(ans, alen-acnt[25]+blen-bcnt[25]);

        return ans;
    }
};
