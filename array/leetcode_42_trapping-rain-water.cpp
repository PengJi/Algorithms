class Solution {
public:
    // 双指针法
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int n = height.size();
        int left = 0, right = n - 1;
        int ans = 0;

        int l_max = height[0];
        int r_max = height[n - 1];

        while (left <= right) {
            l_max = max(l_max, height[left]);
            r_max = max(r_max, height[right]);

            if (l_max < r_max) {
                ans += l_max - height[left];
                left++; 
            } else {
                ans += r_max - height[right];
                right--;
            }
        }

        return ans;
        
    }
};