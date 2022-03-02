// 二分法

typedef long long LL;

class Solution {
public:
    bool check(LL mid, vector<int>& time, int totalTrips) {
        LL total = 0;
        for(int t : time) {
            total += mid / t;
            if(total >= totalTrips) return true;
        }
        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        LL l = 1, r = 1e14;
        while(l < r) {
            LL mid = l + r >> 1;
            if(check(mid, time, totalTrips)) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};
