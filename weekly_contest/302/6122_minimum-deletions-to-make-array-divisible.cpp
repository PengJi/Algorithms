class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int d = 0;
        for(auto x : numsDivide) d = gcd(d, x);

        int res = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(d % nums[i] == 0) break;
            else res++;
        }

        if(res == nums.size()) res = -1;
        return res;
    }
};
