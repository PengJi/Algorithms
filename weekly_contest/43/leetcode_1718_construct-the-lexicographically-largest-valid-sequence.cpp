/**
 * 1718. 构建字典序最大的可行序列
 * https://leetcode-cn.com/problems/construct-the-lexicographically-largest-valid-sequence/
 */

class Solution {
public:
    vector<int> ans;
    vector<bool> visited;

    // 回溯法
    // https://leetcode-cn.com/problems/construct-the-lexicographically-largest-valid-sequence/solution/shuang-bai-lei-si-ba-huang-hou-biao-zhun-9qe0/
    vector<int> constructDistancedSequence(int n) {
        visited.resize(n+1, false);
        ans.resize(2 * (n-1) + 1, 0);
        backtrack(0);
        return ans;
    }

    bool backtrack(int pos) {
        int n = visited.size() - 1;
        if(pos >= ans.size())  // pos 下一个要填的位置
            return true;
        if(ans[pos] != 0)
            return backtrack(pos + 1);
        for(int i = n; i >= 1; i--) {
            if(visited[i]) continue;
            if(i == 1) {
                visited[i] = true;
                ans[pos] = 1;
                if(backtrack(pos + 1)) return true;
                visited[i] = false;
                ans[pos] = 0;
                return false;
            } else {
                if(pos + i >= ans.size()) continue;
                if(ans[pos + i] != 0) continue;
                ans[pos] = i;
                ans[pos+i] = i;
                visited[i] = true;
                if(backtrack(pos+1)) return true;
                ans[pos] = 0;
                ans[pos+i] = 0;
                visited[i] = false;
            }
        }

        return false;
    }
};
