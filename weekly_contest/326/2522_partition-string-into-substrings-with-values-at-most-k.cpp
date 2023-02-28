/**
 * 2522. 将字符串分割成值不超过 K 的子字符串
 * https://leetcode.cn/problems/partition-string-into-substrings-with-values-at-most-k/description/
*/

#define LL long long

class Solution {
public:
    // 贪心
    int minimumPartition(string s, int k) {
        LL t = 0;

        int ans = 1;
        for (char c : s) {
            if (c - '0' > k)
                return -1;

            if (t * 10 + c - '0' > k) {
                ans++;
                t = 0;
            }

            t = t * 10 + c - '0';
        }

        return ans;
    }
};
