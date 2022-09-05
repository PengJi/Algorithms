/**
 * 217. 存在重复元素
 * 给定一个整数数组，判断是否存在重复元素。
 * 如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。
 * 
 * https://leetcode-cn.com/problems/contains-duplicate/
 */

class Solution {
public:
    // 哈希表法
    // https://leetcode-cn.com/problems/contains-duplicate/solution/cjian-ji-dai-ma-duo-chong-fang-fa-by-orangeman-6/
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int n : nums) {
            mp[n]++;
            if(mp[n] > 1) return true;
        }

        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(auto n: nums) {
            if(st.count(n)) return true;
            else st.insert(n);
        }
        return false;
    }
};
