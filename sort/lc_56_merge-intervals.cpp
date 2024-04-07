/**
 * 56. 合并区间
 * https://leetcode-cn.com/problems/merge-intervals/
 */

class Solution {
public:
    // 排序
    // 时间复杂度：O(nlogn)
    // 空间复杂度：O(n)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res{intervals[0]};
        for (int i = 1; i < intervals.size(); i++) {
            if (res.back()[1] >= intervals[i][0]) {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }

    static bool cmp(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }

    // 排序，修改排序方式
    // 时间复杂度：O(nlogn)
    // 空间复杂度：O(n)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        // 排序
        // sort(intervals.begin(), intervals.end())
        sort(intervals.begin(), intervals.end(), [&](vector<int>& l, vector<int>& r) { return l[0] < r[0]; });
        vector<vector<int>> res{intervals[0]};  // 将第一个数组放入结果中

        for (int i = 1; i < intervals.size(); ++i) {
            // 比较结果中最后一个区间右值的与原始区间中的左值
            if (res.back()[1] >= intervals[i][0]) {
                res.back()[1] = max(res.back()[1], intervals[i][1]);  // 更新结果中区间的右值
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

class Solution {
public:
    // 思路同上
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        res.emplace_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (res.back()[1] >= intervals[i][0])
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            else
                res.emplace_back(intervals[i]);
        }

        return res;
    }
};
