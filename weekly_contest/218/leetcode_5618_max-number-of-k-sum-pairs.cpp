/**
 * 5618. K 和数对的最大数目
 * https://leetcode-cn.com/problems/max-number-of-k-sum-pairs/
 */

class Solution {
public:
    int maxOperations(vector<int>& a, int m) {
        map<int, int> cnt;
        for (auto& x : a) cnt[x]++;
        int ret = 0;
        for (auto& [x, v] : cnt) {
            int y = m - x;
            if (y < x) continue;
            if (x != y) {
                ret += min(cnt[x], cnt[y]);
            } else {
                ret += cnt[x] / 2;
            }
        }
        return ret;

    }
};
