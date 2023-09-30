/**
 * 2790. 长度递增组的最大数目
 * https://leetcode.cn/problems/maximum-number-of-groups-with-increasing-length/description/
*/
class Solution {
private:
    bool check(int m, vector<int> cnt, const int n) {
        for (int i = m, j = n; i >= 1; i--) {
            int sum = 0;
            while (1) {
                while (j > 0 && !cnt[j])
                    --j;

                if (j <= 0)
                    return false;

                while (cnt[j] && sum + j < i) {
                    sum += j;
                    --cnt[j];
                }

                if (cnt[j])
                    break;
            }

            --cnt[j];
            if (min(i, j) - (i - sum) > 0) {
                ++cnt[min(i, j) - (i - sum)];
            }
        }

        return true;
    }

public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        const int n = usageLimits.size();

        vector<int> cnt(n + 1, 0);

        for (int x : usageLimits)
            ++cnt[min(n, x)];

        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid + 1, cnt, n)) l = mid + 1;
            else r = mid;
        }

        return l;
    }
};
