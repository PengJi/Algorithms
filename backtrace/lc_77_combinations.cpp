/**
 * 77. 组合
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 *
 * https://leetcode-cn.com/problems/combinations/
 */

class Solution {
public:
    // 回溯法
    // 时间复杂度：
    // 空间复杂度：O(Cnk)
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(1, tmp, n, k, res);

        return res;
    }

    void backtrack(int first, vector<int>& vec, int n, int k, vector<vector<int>>& res) {
        if (vec.size() == k) {
            res.push_back(vec);
            return;
        }

        for (int i = first; i < n + 1; i++) {
            vec.push_back(i);
            backtrack(i + 1, vec, n, k, res);
            vec.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combine(int n, int k) {
        dfs(0, 1, n, k);
        return ans;
    }

    void dfs(int idx, int start, int n, int k) {
        if (idx == k) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i <= n; i++) {
            path.push_back(i);
            dfs(idx + 1, i + 1, n, k);
            path.pop_back();
        }
    }
};
