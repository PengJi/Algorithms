typedef long long ll;

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        sort(beans.begin(), beans.end());
        ll total = accumulate(beans.begin(), beans.end(), 0LL);
        ll res = total;
        for(int i = 0; i < n; i++) {
            res = min(res, total - (ll)beans[i] * (n - i));
        }
        return res;
    }
};