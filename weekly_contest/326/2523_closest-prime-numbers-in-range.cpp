/**
 * 2523. 范围内最接近的两个质数
 * https://leetcode.cn/problems/closest-prime-numbers-in-range/
*/

const int N = 1000010;

int n;
int primes[N], cnt;
bool st[N];

class Solution {
public:
    // 线性筛质数
    void get_primes(int n) {
        cnt = 0;
        for (int i = 2; i <= n; i ++ ) {
            if (!st[i]) primes[cnt ++ ] = i;
            for (int j = 0; primes[j] <= n / i; j ++ ) {
                st[primes[j] * i] = true;
                if (i % primes[j] == 0) break;
            }
        }
    }

    vector<int> closestPrimes(int left, int right) {
        get_primes(right);

        vector<int> res(2, -1);
        int d = 1e8;
        for (int i = 1; i < cnt; i ++ ) {
            int a = primes[i - 1], b = primes[i];
            if (a >= left && b - a < d) {
                d = b - a;
                res[0] = a, res[1] = b;
            }
        }

        return res;
    }
};
