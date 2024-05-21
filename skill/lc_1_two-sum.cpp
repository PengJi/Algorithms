/**
 * 1. 两数之和
 * https://leetcode-cn.com/problems/two-sum/
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> mp;  // 存储<值，下标>
        mp[nums[0]] = 0;
        int cur;

        for (int i = 1; i < nums.size(); i++) {
            cur = target - nums[i];
            if (mp.count(cur) != 0 && mp[cur] != i) {
                res.push_back(i);
                res.push_back(mp[cur]);
                break;
            }
            mp[nums[i]] = i;
        }

        return res;
    }
};
