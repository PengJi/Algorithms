class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // a & b 的特征：a & b <= a, a & b <= b;
        // 找到最大值
        int m = 0;
        for(auto x: nums) m = max(m, x);
        
        // 找到最大值的长度
        int n= 0;
        int res = 0;
        for(auto x: nums) {
            if(x == m) {
                n++;
                res = max(res, n);
            } else {
                n = 0;
            }
        }

        return res;
    }
};
