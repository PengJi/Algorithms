class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1 && k % 2 == 1) return -1;
        
        int res = (k < n) ? nums[k] : 0;
        for(int i = 0; i < n && i < k-1; i++) {
            res = max(res, nums[i]);
        }

        return res;
    }
};
