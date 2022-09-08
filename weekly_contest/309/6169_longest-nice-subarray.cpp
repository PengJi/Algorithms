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

class Solution {
public:
    // 滑动窗口
    int longestNiceSubarray(vector<int>& nums) {
        int cnt[31] = {0};  // 在数据范围内，最多有 31 位
        int res = 1;
        for(int i =0, j = 0, tot = 0; i < nums.size(); i++) {  // i 为右便捷，j 为左边界
            // 每位最多只能有一个1，如果超过1，记录超过的个数
            for(int k = 0; k < 31; k++) {
                if(nums[i] >> k & 1) {
                    if(++cnt[k] > 1) tot++;
                }
            }

            // 向右移动左边界，直至滑动窗口内的数字每一位的 1 的个数不超过 1
            while(tot) {
                for(int k = 0; k < 31; k++) {
                    if(nums[j] >> k & 1) {
                        if(--cnt[k] == 1) tot--;
                    }
                }
                j++;
            }

            res = max(res, i-j+1);
        }

        return res;
    }
};
