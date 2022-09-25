class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();

        // 记录满足条件的位置
        vector<bool> vec(n, false);
        
        // 从右向左扫描，找到所有后续至少 k 个元素非递减的元素的位置
        int len = 1;
        for(int i = n-2; i >= 0; i--) {
            if(len >= k) vec[i] = true;
            
            if(nums[i] <= nums[i+1]) len++;
            else len = 1;
        }

        // 从左向右扫描，找到所有前面 k 个元素非递增的元素的位置
        vector<int> res;
        len = 1;
        for(int i = 1; i < n; i++) {
            if(len >= k && vec[i]) res.push_back(i);

            if(nums[i] <= nums[i-1]) len++;
            else len = 1;
        }

        return res;
    }
};
