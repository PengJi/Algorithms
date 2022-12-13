/**
 * 204. 计数质数
 * https://leetcode-cn.com/problems/count-primes/
 */

class Solution {
public:
    // https://www.acwing.com/solution/content/314/
    int countPrimes(int n) {
        vector<int> primes;
        vector<bool> st(n + 1);
        for (int i = 2; i < n; i ++ )
        {
            if (!st[i]) primes.push_back(i);
            for (int j = 0; i * primes[j] < n; j ++ )
            {
                st[i * primes[j]] = true;
                if (i % primes[j] == 0) break;
            }
        }
        return primes.size();
    }
};

class Solution {
public:
    // 最优的算法
    // 时间复杂度：O(n)
    int countPrimes(int n) {
        vector<int> primes;
        vector<bool> st(n + 1);

        for (int i = 2; i < n; i ++ ) {
            if (!st[i]) primes.push_back(i);

            for (int j = 0; i * primes[j] < n; j ++ ) {
                st[i * primes[j]] = true;
                if (i % primes[j] == 0) break;
            }
        }

        return primes.size();
    }
};
