/**
 * 2899. 上一个遍历的整数
 * https://leetcode.cn/problems/last-visited-integers/description/
*/
class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> nums, ans;
        int k = 0;
        for (const auto &w : words) {
            if (w == "prev") {
                ++k;
                if (k > nums.size()) ans.push_back(-1);
                else ans.push_back(nums[nums.size() - k]);
            } else {
                k = 0;
                nums.push_back(stoi(w));
            }
        }

        return ans;
    }
};
