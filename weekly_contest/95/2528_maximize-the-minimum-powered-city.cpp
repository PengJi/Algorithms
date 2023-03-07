#define LL long long

class Solution {
private:
    bool check(LL m, vector<int> stations, int d, int k) {
        const int n = stations.size();

        int l = 0, r = d;

        LL tot = 0;
        for (int i = 0; i < r; i++)
            tot += stations[i];

        for (int i = 0; i < n; i++) {
            if (r < n)
                tot += stations[r];


            if (tot < m) {
                if (k < m - tot)
                    return false;

                k -= m - tot;

                if (r < n)
                    stations[r] += m - tot;

                tot = m;
            }

            if (i - l == d) {
                tot -= stations[l];
                l++;
            }

            r++;
        }

        return true;
    }

public:
    LL maxPower(vector<int>& stations, int r, int k) {
        LL lo = 0, hi = 1000000000000000ll;


        while (lo < hi) {
            LL mid = (lo + hi) >> 1;

            if (check(mid + 1, stations, r, k)) lo = mid + 1;
            else hi = mid;
        }

        return lo;
    }
};
