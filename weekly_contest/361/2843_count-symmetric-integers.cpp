/**
 * 2843. 统计对称整数的数目
 * https://leetcode.cn/problems/count-symmetric-integers/description/
*/
const int N = 10;

class Solution {
private:
    int p[N];

    bool check(int x) {
        int m = 0;
        while (x) {
            p[m++] = x % 10;
            x /= 10;
        }

        if (m % 2 != 0)
            return false;

        int s = 0;
        for (int i = 0; i < m / 2; i++)
            s += p[i];

        for (int i = m / 2; i < m; i++)
            s -= p[i];

        return s == 0;
    }

public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        while (low <= high) {
            if (check(low))
                ++ans;

            ++low;
        }

        return ans;
    }
};
