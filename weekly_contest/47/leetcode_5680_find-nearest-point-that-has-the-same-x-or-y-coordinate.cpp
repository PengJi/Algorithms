/**
 * 5680. 找到最近的有相同 X 或 Y 坐标的点
 * https://leetcode-cn.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/
 */

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int tmp_len;
        int min_idx = -1, min_len = INT_MAX;
        for(int i = points.size()-1; i >= 0; i--) {
            if(x == points[i][0] || y == points[i][1]) {
                tmp_len = abs(x-points[i][0]) + abs(y-points[i][1]);
                if(tmp_len <= min_len) {
                    min_len = tmp_len;
                    min_idx = i;
                }
            }
        }
        
        return min_idx;
    }
};
