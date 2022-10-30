/**
 * 6222. 美丽整数的最小增量
 * https://leetcode.cn/problems/minimum-addition-to-make-integer-beautiful/
*/
#define LL long long

class Solution {
private:
    LL combine(const vector<int> &b) {
        LL r = 0;
        for (int i = b.size() - 1; i >= 0; i--)
            r = r * 10 + b[i];

        return r;
    }

public:
    LL makeIntegerBeautiful(LL n, int target) {
        vector<int> b;
        LL t = n;

        int s = 0;
        while (t) {
            s += t % 10;
            b.push_back(t % 10);
            t /= 10;
        }

        if (s <= target)
            return 0;

        b.push_back(0);

        for (int i = 0; i < b.size() - 1; i++) {
            if (b[i] == 0)
                continue;

            s = s - b[i] + 1;
            b[i + 1]++;
            b[i] = 0;

            if (b[i + 1] == 10)
                continue;

            if (s <= target)
                break;
        }

        return combine(b) - n;
    }
};
