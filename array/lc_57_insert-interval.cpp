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

class Solution {
public:
    // 将区间分为三部分，在新区建左侧，在新区建右侧，与新区建重合，重合的部分合并区间
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int left = newInterval[0], right = newInterval[1];
        bool placed = false;  // 新区间是否被插入

        for(auto x: intervals) {
            if(x[1] < left) {  // 在插入区间的左侧
                res.push_back(x);
            } else if(x[0] > right) {  // 在插入区间的右侧
                if(!placed) {  // 如果新区建没有被插入，则先插入新区间
                    res.push_back({left, right});
                    placed = true;
                }
                res.push_back(x);
            } else {  // 区间重叠
                left = min(left, x[0]);
                right = max(right, x[1]);
            }
        }

        if(!placed) {
            res.push_back({left, right});
        }

        return res;
    }
};
