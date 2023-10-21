/**
 * 2818. 操作使得分最大
 * https://leetcode.cn/problems/apply-operations-to-maximize-score/description/
*/
const int N = 100010;
const int mod = 1000000007;

#define LL long long

class Solution {
private:
    bool isNotPrime[N];
    int prime[N], m;

    void init() {
        memset(isNotPrime, false, sizeof(isNotPrime));
        m = 0;

        for (int i = 2; i < N; i++) {
            if (!isNotPrime[i])
                prime[m++] = i;

            for (int j = 0; j < m && i * prime[j] < N; j++) {
                isNotPrime[i * prime[j]] = true;
                if (i % prime[j] == 0)
                    break;
            }
        }
    }

    LL power(int x, LL y) {
        LL res = 1, p = x;
        for (; y; y >>= 1) {
            if (y & 1)
                res = res * p % mod;

            p = p * p % mod;
        }

        return res;
    }

public:
    int maximumScore(vector<int>& nums, int k) {
        init();

        const int n = nums.size();
        vector<int> p(n, 0);

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            for (int j = 0; prime[j] * prime[j] <= x; j++) {
                if (x % prime[j] == 0)
                    ++p[i];

                while (x % prime[j] == 0)
                    x /= prime[j];
            }

            if (x > 1)
                ++p[i];
        }

        stack<int> st;
        vector<int> l(n), r(n);

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || p[i] > p[st.top()])) {
                int t = st.top();
                st.pop();

                r[t] = i;
                if (!st.empty()) l[t] = st.top();
                else l[t] = -1;
            }

            st.push(i);
        }

        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int x, int y) {
            return nums[x] > nums[y];
        });

        int ans = 1;
        for (int x : id) {
            LL tot = (LL)(x - l[x]) * (r[x] - x);
            if (k < tot) {
                ans = power(nums[x], k) * ans % mod;

                break;
            }

            k -= tot;
            ans = power(nums[x], tot) * ans % mod;
        }

        return ans;
    }
};
