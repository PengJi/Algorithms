class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int cnt[40] = {0};
        int res = 0;
        for(int i = 0, j = 0, tot = 0; i < nums.size(); i++) {
            for(int k = 0; k < 31; k++) {
                if(nums[i] >> k & 1) {
                    if (++cnt[k] > 1) tot++;
                }
            }

            while(tot) {
                for(int k = 0; k < 31; k++) {
                    if(nums[j] >> k & 1){
                        if(--cnt[k] == 1) tot--;
                    }
                }
                j++;
            }

            res = max(res, i - j + 1);
        }

        return res;
    }
};
