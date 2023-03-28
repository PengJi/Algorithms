#define LL long long

class Solution {
public:
    LL putMarbles(vector<int>& weights, int k) {
        priority_queue<int> ma;
        priority_queue<int, vector<int>, greater<int>> mi;

        const int n = weights.size();
        LL res1 = 0, res2 = 0;

        for (int i = 0; i < n - 1; i++) {
            int w = weights[i] + weights[i + 1];

            ma.push(w); res1 += w;
            mi.push(w); res2 += w;

            if (i >= k - 1) {
                res1 -= ma.top(); ma.pop();
                res2 -= mi.top(); mi.pop();
            }
        }

        return res2 - res1;
    }
};
