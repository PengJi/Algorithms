/**
 * 2442. 反转之后不同整数的数目
 * https://leetcode.cn/problems/count-number-of-distinct-integers-after-reverse-operations/
*/
class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        // 初始化
        unordered_set<int> st(nums.begin(), nums.end());

        for(auto x : nums) {
            int t = 0;
            
            // 反转数字，比较巧妙
            while(x) {
                t = t * 10 + x % 10;
                x /= 10;
            }

            // 重复元素不插入
            st.insert(t);
        }

        return st.size();
    }
};
