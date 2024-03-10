/**
 * 216. 组合总和 III
 * 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
 *
 * https://leetcode.cn/problems/combination-sum-iii/
 */
class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    // 回溯法
    // https://leetcode-cn.com/problems/combination-sum-iii/solution/zu-he-zong-he-iii-by-leetcode-solution/
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, 9, k, n);
        return ans;
    }

    void dfs(int cur, int n, int k, int sum) {
        if (temp.size() + (n - cur + 1) < k || temp.size() > k) {
            return;
        }
        if (temp.size() == k && accumulate(temp.begin(), temp.end(), 0) == sum) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(cur);
        dfs(cur + 1, n, k, sum);
        temp.pop_back();
        dfs(cur + 1, n, k, sum);
    }
};

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return ans;
    }

    // start 表示从那个数开始枚举
    void dfs(int k, int n, int start) {
        if (k == 0) {
            if (k == 0) ans.push_back(path);
            return;
        }

        for (int i = start; i <= 10 - k; i++)
            if (n >= i) {
                path.push_back(i);
                dfs(k - 1, n - i, i + 1);
                path.pop_back();
            }
    }
};
