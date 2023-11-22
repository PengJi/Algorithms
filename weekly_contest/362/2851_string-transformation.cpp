/**
 * 2851. 字符串转换
 * https://leetcode.cn/problems/string-transformation/description/
*/
#define LL long long

const int mod = 1000000007;

struct Mat {
    int a[2][2];
    Mat() {
        memset(a, 0, sizeof(a));
    }

    Mat operator * (const Mat &y) {
        Mat res;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    res.a[i][j] = (res.a[i][j] + (LL)(a[i][k]) * y.a[k][j]) % mod;

        return res;
    }
};

class Solution {
private:
    int n;

    vector<int> get_nxt(const string &s) {
        vector<int> nxt(n);
        nxt[0] = -1;

        for (int i = 1, j = -1; i < n; i++) {
            while (j >= 0 && s[j + 1] != s[i])
                j = nxt[j];

            if (s[j + 1] == s[i])
                ++j;

            nxt[i] = j;
        }

        return nxt;
    }

    int find(const string &s, const string &t, const vector<int> &nxt) {
        string w = t + t;

        for (int i = 0, j = -1; i < w.size(); i++) {
            while (j >= 0 && s[j + 1] != w[i])
                j = nxt[j];

            if (s[j + 1] == w[i])
                ++j;

            if (j == n - 1)
                return i - n + 1;
        }

        return -1;
    }

    Mat power(Mat x, LL y) {
        Mat tot, p = x;
        tot.a[0][0] = tot.a[1][1] = 1;

        for(; y; y >>= 1) {
            if (y & 1) tot = tot * p;
            p = p * p;
        }

        return tot;
    }

public:
    int numberOfWays(string s, string t, LL k) {
        n = s.size();
        vector<int> nxt = get_nxt(s);

        int fst = find(s, t, nxt);
        if (fst == -1)
            return 0;

        Mat p;
        p.a[0][0] = 0; p.a[0][1] = n - 1;
        p.a[1][0] = 1; p.a[1][1] = n - 2;
        Mat tot = power(p, k);

        int ans = 0;
        if (fst == 0) ans += tot.a[0][0];
        else ans += tot.a[1][0];

        int r = n;
        if (n % (n - nxt[n - 1] - 1) == 0)
            r = n - nxt[n - 1] - 1;

        ans = (ans + (LL)((n - fst - 1) / r) * tot.a[1][0]) % mod;

        return ans;
    }
};
