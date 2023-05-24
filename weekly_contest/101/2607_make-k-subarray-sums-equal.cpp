#define LL long long

class Solution {
private:
    LL solve(vector<int> &arr) {
        const int m = arr.size();

        nth_element(arr.begin(), arr.begin() + m / 2, arr.end());

        LL res = 0;
        for (int i = 0; i < m; i++)
            res += abs(arr[i] - arr[m / 2]);

        return res;
    }

public:
    LL makeSubKSumEqual(vector<int>& arr, int k) {
        const int n = arr.size();
        int p = gcd(n, k);

        vector<vector<int>> g(p);
        for (int i = 0; i < n; i++)
            g[i % p].push_back(arr[i]);

        LL ans = 0;
        for (int i = 0; i < p; i++)
            ans += solve(g[i]);

        return ans; 
    }
};
