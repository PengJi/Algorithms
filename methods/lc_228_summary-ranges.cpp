/**
 * 228. 汇总区间
 * https://leetcode-cn.com/problems/summary-ranges/
 */

class Solution {
public:
    // https://www.acwing.com/solution/content/324/
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int st, ed;
        for (int i = 0; i < nums.size(); i ++ )
        {
            int x = nums[i];
            if (!i) st = ed = x;
            else if (x == ed + 1) ed ++ ;
            else
            {
                res.push_back(to_string(st) + (st == ed ? "" : "->" + to_string(ed)));
                st = ed = x;
            }
        }
        if (nums.size()) res.push_back(to_string(st) + (st == ed ? "" : "->" + to_string(ed)));
        return res;
    }
};
