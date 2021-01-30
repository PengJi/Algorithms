/**
 * 57. 插入区间
 * https://leetcode-cn.com/problems/insert-interval/
 */

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0], right = newInterval[1];
        bool placed = false;

        vector<vector<int>> ans;
        for(auto interval: intervals) {
            if(interval[0] > right) {  // 在插入区间的右侧
                if(!placed) {
                    ans.push_back({left, right});
                    placed = true;
                }
                ans.push_back(interval);
            } else if(interval[1] < left) {  // 在插入区间的左侧
                ans.push_back(interval);
            } else {  // 区间重叠
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }

        if(!placed) {
            ans.push_back({left, right});
        }

        return ans;
    }
};
