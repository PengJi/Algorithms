/**
 * 84. 柱状图中最大的矩形
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
 */

class Solution {
public:
    // 暴力法（超出时间限制）
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(1)
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        if(len == 0) return 0;

        int max = 0, tmpArea, tmpMinHeight;
        for(int i = 0; i < len; i++){
            tmpMinHeight = heights[i];
            for(int j = i; j < len; j++){
                if(tmpMinHeight > heights[j]){
                    tmpMinHeight = heights[j];
                }
                tmpArea = tmpMinHeight * (j - i + 1);
                if(tmpArea > max){ 
                    max = tmpArea;
                }
            }
        }

        return max;
    }

    // 单调栈
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        vector<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++)
        {
            while (!st.empty() && heights[st.back()] > heights[i])
            {
                int cur = st.back();
                st.pop_back();
                int left = st.back() + 1;
                int right = i - 1;
                ans = max(ans, (right - left + 1) * heights[cur]);
            }
            st.push_back(i);
        }
        return ans;
    }
};
