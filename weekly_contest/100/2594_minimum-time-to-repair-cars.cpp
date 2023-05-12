typedef long long LL;

class Solution {
private:
    bool check(LL m, const vector<int> &ranks, int cars) {
        LL tot = 0;
        for (int r : ranks) {
            tot += sqrt(m / r);
            if (tot >= cars)
                return true;
        }

        return tot >= cars;
    }

public:
    // 二分
    LL repairCars(vector<int>& ranks, int cars) {
        LL l = 0, r = 100000000000000ll;

        while (l < r) {
            LL mid = (l + r) >> 1;
            if (check(mid, ranks, cars)) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};
