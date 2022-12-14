/**
 * 229. 多数元素 II
 * https://leetcode-cn.com/problems/majority-element-ii/
 */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int r1, r2, c1 = 0, c2 = 0;
        for(auto i : nums) {
            if(c1 && r1 == i) c1++;
            else if(c2 && r2 == i) c2++;
            else if(!c1) r1 = i, c1++;
            else if(!c2) r2 = i, c2++;
            else c1--, c2--;
        }
        c1 = 0, c2 = 0;
        for(auto i : nums) {
            if(r1 == i) c1++;
            else if(r2 == i) c2++;
        }

        vector<int> res;
        int len = nums.size();
        if(c1 > len/3) res.push_back(r1);
        if(c2 > len/3) res.push_back(r2);

        return res;
    }
};
