/**
 * 39. 组合总和
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，
 * 找出 candidates 中所有可以使数字和为 target 的组合。
 * candidates 中的数字可以无限制重复被选取。

 * https://leetcode-cn.com/problems/combination-sum/
 */

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        findAns(candidates, target, 0);
        return ansSet;
    }

private:
    vector<vector<int>> ansSet;
    vector<int> oneAns;

    void findAns(vector<int>& candidates, int target, int startIndex) {
        //结束条件
        if(target == 0) {
            ansSet.push_back(oneAns);
            return;
        }

        //减枝
        if(target < 0) return;

        // i从startIndex，传入可以避免更深层的节点使用其父节点及其父节点之上的值(总的来说就是之前用过的值)，避免答案重复
        for(int i = startIndex; i < candidates.size(); ++i) {
            if(target >= 0) {
                oneAns.push_back(candidates[i]);
                // 得到一个加法因子后，target值要变小
                findAns(candidates, target-candidates[i], i);
                //撤销操作，以免上次结果影响下次的搜索结果
                oneAns.pop_back();
            }
            else break;
        }
    }
};

class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        dfs(c, 0, target);
        return ans;
    }

    void dfs(vector<int>& c, int idx, int target) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        if (idx == c.size()) return;

        for (int i = 0; c[idx] * i <= target; i++) {
            dfs(c, idx + 1, target - c[idx] * i);
            path.push_back(c[idx]);
        }

        for (int i = 0; c[idx] * i <= target; i++) {
            path.pop_back();
        }
    }
};
