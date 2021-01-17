/**
 * 5653. 可以形成最大正方形的矩形数目
 * https://leetcode-cn.com/problems/number-of-rectangles-that-can-form-the-largest-square/
 */

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLen = 0;
        int tmpLen;
        int ans = 1;
        for(int i = 0; i < rectangles.size(); i++) {
            tmpLen = min(rectangles[i][0], rectangles[i][1]);
            if(tmpLen > maxLen) {
                maxLen = tmpLen;
                ans = 1;
            } else if(tmpLen == maxLen) {
                ans++;
            }
        }

        return ans;
    }
};
