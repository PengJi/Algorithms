class Solution {
public:
    // 倒叙处理
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for (int i = nums.size() - 1; i >= 0; i--) {
            int x = nums[i];
            while (x) {
                ans.push_back(x % 10);
                x /= 10;
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
