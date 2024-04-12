/**
 * 1. 两数之和
 * https://leetcode-cn.com/problems/two-sum/
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> mp;  // 存储<值，键>
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

class Solution {
public:
    // 暴力法
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(1)
    vector<int> twoSum1(vector<int>& nums, int target) {
        vector<int> v;
        int length = nums.size();
        for (int i = 0; i < length - 1; i++) {
            for (int j = i + 1; j < length; j++) {
                if (nums[i] + nums[j] == target) {
                    v.push_back(i);
                    v.push_back(j);
                }
            }
        }
        return v;
    }
};
