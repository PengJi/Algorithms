class Solution {
public:
    int alternateDigitSum(int n) {
        int res = 0, c = 0;

        while (n) {
            if (c & 1) res += n % 10;
            else res -= n % 10;

            n /= 10;
            ++c;
        }

        if (c & 1)
            res = -res;

        return res;
    }
};
