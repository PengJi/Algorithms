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

    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        int l = 0, r = 0;
        while(r < n) {
            while(r+1 < n){
                if(nums[r]+1 == nums[r+1]) r++;
                else break;
            }
            if(l == r) {
                res.push_back(to_string(nums[l]));
            } else {
                res.push_back(to_string(nums[l]) + "->" + to_string(nums[r]));
            }
            r++;
            l = r;
        }

        return res;
    }
};
