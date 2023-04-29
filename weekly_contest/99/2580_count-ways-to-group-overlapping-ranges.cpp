class Solution {
public:
    int countWays(vector<vector<int>>& g) {
        int n = g.size(), k = 0, p = -1, mod = 1e9 + 7;
        sort(g.begin(), g.end());
        for(int i = 0;i < n;i ++)
        {
            int x = g[i][0], y = g[i][1];
            if(x > p)  k ++;
            p = max(p, y);
        }
        int res = 1;
        long long t = 2;
        while(k)
        {
            if(k & 1)  res = res * t % mod;
            t = (long long)t * t % mod;
            k >>= 1;
        }
        return res;
    }
};
