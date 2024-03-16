/**
 * 455. 分发饼干
 * https://leetcode-cn.com/problems/assign-cookies/
 */

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;
        int res = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                res++;
                i++;
            }

            j++;
        }

        return res;
    }
};

class Solution {
public:
    // 排序，使用双指针对比
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int res = 0;
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                res++;
                i++;
            }
            j++;
        }

        return res;
    }
};
