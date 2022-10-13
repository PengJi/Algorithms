/**
 * 179. 最大数
 * https://leetcode-cn.com/problems/largest-number/
 */

class Solution {
public:
    // https://www.acwing.com/activity/content/code/content/417230/
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int x, int y) {
            string a = to_string(x), b = to_string(y);
            return a + b > b + a;
        });
        
        string res;
        for (auto x: nums) res += to_string(x);
        int k = 0;
        while (k + 1 < res.size() && res[k] == '0') k ++ ;
        return res.substr(k);
    }
};

class Solution {
public:
    // 关键在于对元素进行排序，需要自定义排序规则
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int x, int y) {
            string a = to_string(x), b = to_string(y);
            // 两数拼接后比较，较大的数在前面
            return a + b > b + a;
        });

        // 预防 [0, 0]，排序后最大的数为0，则结果为0
        if(nums[0] == 0) return "0";
        
        string res;
        for(auto x : nums) res += to_string(x);

        return res;
    }
};
