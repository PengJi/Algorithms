/**
 * 18. 四数之和
 * https://leetcode-cn.com/problems/4sum/
 */

class Solution {
public:
    // 排序 + 双指针法
    // https://leetcode-cn.com/problems/4sum/solution/shuang-zhi-zhen-jie-fa-can-zhao-san-shu-zhi-he-ge-/
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        if(nums.size() < 4) return ans;

        int a, b, c, d, len = nums.size();
        for(a = 0; a <= len-4; a++) {
            if(a > 0 && nums[a] == nums[a-1]) continue;
            for(b = a+1; b <= len-3; b++) {
                if(b > a+1 && nums[b] == nums[b-1]) continue;
                c = b+1, d = len-1;
                while(c < d) {
                    if(nums[a] + nums[b] + nums[c] + nums[d] < target) 
                        c++;
                    else if(nums[a] + nums[b] + nums[c] + nums[d] > target)
                        d--;
                    else {
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                        while(c < d && nums[c+1] == nums[c])
                            c++;
                        while(c < d && nums[d-1] == nums[d])
                            d--;
                        c++;
                        d--;
                    }
                }
            }
        }

        return ans;
    }
};
