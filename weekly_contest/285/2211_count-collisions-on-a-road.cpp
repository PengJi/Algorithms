class Solution {
public:
    int countCollisions(string directions) {
        int res = 0, n = directions.size();
        int l = 0, r = n-1;

        while(l <= r && directions[l] == 'L') l++;
        while(l <= r && directions[r] == 'R') r--;

        for(int i = l; i <= r; i++) {
            if(directions[i] == 'L' || directions[i] == 'R') res++;
        }

        return res;
    }
};
