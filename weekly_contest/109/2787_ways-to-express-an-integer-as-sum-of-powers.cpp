/**
 * 2787. 将一个数字表示成幂的和的方案数
 * https://leetcode.cn/problems/ways-to-express-an-integer-as-sum-of-powers/description/
*/
class Solution {
private:
    int power(int k, int x) {
        int p = 1;
        for (; x; x--)
            p *= k;

        return p;
    }

public:
    int numberOfWays(int n, int x) {
        const int mod = 1000000007;
        vector<int> f(n + 1, 0);

        f[0] = 1;
        for (int i = 1, p = 1; p <= n; p = power(++i, x))
            for (int j = n; j >= p; j--)
                f[j] = (f[j] + f[j - p]) % mod;

        return f[n];
    }
};

作者：wzc1995
链接：https://www.acwing.com/solution/content/196680/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。