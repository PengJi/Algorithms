/**
 * 217. 存在重复元素
 * https://leetcode-cn.com/problems/contains-duplicate/
 */

class Solution {
public:
    // 哈希表法
    // https://leetcode-cn.com/problems/contains-duplicate/solution/cjian-ji-dai-ma-duo-chong-fang-fa-by-orangeman-6/
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int n : nums) {
            mp[n]++;
            if (mp[n] > 1) return true;
        }

        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (auto n : nums) {
            if (st.count(n))
                return true;
            else
                st.insert(n);
        }
        return false;
    }
};
