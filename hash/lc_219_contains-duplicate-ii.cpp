/**
 * 219. 存在重复元素 II
 * https://leetcode-cn.com/problems/contains-duplicate-ii/
 */

class Solution {
public:
    // 哈希
    // https://leetcode-cn.com/problems/contains-duplicate-ii/solution/hua-jie-suan-fa-219-cun-zai-zhong-fu-yuan-su-ii-by/
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> st;

        for(int i = 0; i < nums.size(); i++) {
            if(st.count(nums[i]) != 0) {
                return true;
            }

            st.insert(nums[i]);

            if(st.size() > k) {
                st.erase(nums[i - k]);
            }
        }

        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.count(nums[i]) && abs(i - mp[nums[i]]) <= k) return true;
            mp[nums[i]] = i;
        }

        return false;
    }
};
