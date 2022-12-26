/**
 * 40. 组合总和 II
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * candidates 中的每个数字在每个组合中只能使用一次。
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/
 */ 

class Solution {
public:
    // 回溯
    // https://leetcode-cn.com/problems/combination-sum-ii/solution/c-di-gui-hui-su-by-yizhe-shi/
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(ans, candidates, 0, target, tmp);

        return ans;
    }

    void dfs(vector<vector<int>>& ans, vector<int>& candidates, int idx, int target, vector<int>& tmp) {
        if(target == 0) {
            ans.push_back(tmp);
            return;
        }

        for(int i = idx; i < candidates.size(); i++) {
            if(candidates[i] <= target) {
                // 检测到重复元素就跳过
                if(i > idx && candidates[i] == candidates[i - 1]) continue;
                tmp.push_back(candidates[i]);
                // 元素不可重复利用，使用下一个即 i+1
                dfs(ans, candidates, i+1, target - candidates[i], tmp);
                tmp.pop_back();
            }
        }
    }
};

class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(), c.end());
        dfs(c, 0, target);

        return ans;
    }

    void dfs(vector<int>& c, int u, int target) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        if (u == c.size()) return;

        int k = u + 1;
        while (k < c.size() && c[k] == c[u]) k ++ ;
        int cnt = k - u;

        for (int i = 0; c[u] * i <= target && i <= cnt; i ++ ) {
            dfs(c, k, target - c[u] * i);
            path.push_back(c[u]);
        }

        for (int i = 0; c[u] * i <= target && i <= cnt; i ++ ) {
            path.pop_back();
        }
    }
};

