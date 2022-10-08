/**
 * 539. 最小时间差
 * https://leetcode-cn.com/problems/minimum-time-difference/
 */

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int res = INT_MAX;
        vector<int> q;

        for(string t : timePoints) {
            int m, n;
            sscanf(t.c_str(), "%d:%d", &m, &n);
            q.push_back(m * 60 + n);
        }
        sort(q.begin(), q.end());
        
        for(int i = 1; i < q.size(); i++) {
            res = min(res, q[i] - q[i-1]);
        }
        res = min(res, 24*60 - q.back() + q[0]);

        return res;
    }
};

class Solution {
public:
    // 排序 + 处理特殊情况：计算末尾与开头的差距
    int findMinDifference(vector<string>& timePoints) {
        vector<int> hm;
        int h, m;
        // 将时间转换为分钟
        for(auto t: timePoints) {
            sscanf(t.c_str(), "%d:%d", &h, &m);
            hm.push_back(h*60+m);
        }

        // 排序
        sort(hm.begin(), hm.end());

        int res = INT_MAX;
        // 计算最小值
        for(int i = 1; i < hm.size(); i++) {
            res = min(res, hm[i] - hm[i-1]);
        }
        // 计算末尾与开头的差距
        res = min(res, 24*60 - hm.back() + hm[0]);

        return res;
    }
};

