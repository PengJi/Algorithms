/**
 * 1726. 同积元组
 * https://leetcode-cn.com/problems/tuple-with-same-product/
 */

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < len; j++) {
                mp[nums[i] * nums[j]]++;
            }
        }

        int ans = 0;
        for(auto c : mp) {
            ans += c.second * (c.second-1)/2;
        }

        return ans*8;
    }
};
