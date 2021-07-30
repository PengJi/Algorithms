/**
 * 264. 丑数 II
 * https://leetcode-cn.com/problems/ugly-number-ii/
 */

class Solution {
public:
    // https://www.acwing.com/activity/content/code/content/451533/
    int nthUglyNumber(int n) {
        vector<int> p(1, 1);
        for(int i = 0, j = 0, k = 0; p.size() < n;) {
            int t = min(p[i]*2, min(p[j]*3, p[k]*5));
            p.push_back(t);
            if(p[i] * 2 == t) i++;
            if(p[j] * 3 == t) j++;
            if(p[k] * 5 == t) k++;
        }

        return p.back();
    }

    int nthUglyNumber(int n) {
        vector<int> s(n);
        s[0] = 1;
        int i = 0, j = 0, k = 0;
        int idx = 1;
        int v2, v3, v5;
        int m;
        while(idx <= n-1) {
            v2 = s[i] * 2;
            v3 = s[j] * 3; 
            v5 = s[k] * 5;
            m = min(v2, min(v3, v5));
            s[idx++] = m;
            if(v2 == m) i++;
            if(v3 == m) j++;
            if(v5 == m) k++;
        }

        return s[n-1];
    }
};
