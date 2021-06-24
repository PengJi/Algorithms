/**
 * 41. 缺失的第一个正数
 * https://leetcode-cn.com/problems/first-missing-positive/
 */
class Solution {
public:
    // 哈希表
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto it : nums) {
            s.insert(it);
        }

        int ans = 1;
        while(s.count(ans)) ans++;

        return ans;
    }

    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 1;

        for(auto& it : nums) {
            if(it != INT_MIN) it--;
        }

        for(int i = 0; i < len; i++) {
            while(nums[i] >= 0 && nums[i] < len && nums[i] != i && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            }
        }

        for(int i = 0; i < len; i++) {
            if(nums[i] != i) return i+1;
        }

        return len+1;
    }
};
