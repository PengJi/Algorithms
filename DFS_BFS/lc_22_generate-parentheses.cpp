/**
 * 22. 括号生成
 * https://leetcode-cn.com/problems/generate-parentheses/
 */

class Solution {
public:
    // dfs
    // 思路：https://leetcode-cn.com/problems/generate-parentheses/solution/hui-su-suan-fa-by-liweiwei1419/
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0) return res;

        // 当前字符串，左括号，右括号，结果
        dfs("", n, n, res);
        return res;
    }

    void dfs(string str, int left, int right, vector<string> &res) {
        // 因为每一次尝试，都使用新的字符串变量，所以无需回溯
        // 在递归终止的时候，直接把它添加到结果集即可，
        if(left == 0 && right == 0){
            res.push_back(str);
            return;
        }

        // 剪枝，左括号可以使用的个数严格大于右括号可以使用的个数
        if(left > right) return;

        if(left > 0) dfs(str+"(", left-1, right, res);
        if(right > 0) dfs(str+")", left, right-1, res);
    }
};

class Solution {
public:
    vector<string> res;

    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return res;
    }

    void dfs(int n, int lc, int rc, string str) {
        if(lc == n && rc == n) res.push_back(str);
        else {
            if(lc < n) dfs(n, lc+1, rc, str+'(');  // 当左括号数量小于 n，则可以添加左括号
            if(rc < n && rc < lc) dfs(n, lc, rc+1, str+')');  // 当右括号数量小于 n，并且左括号数量大于右括号数量时，可以添加右括号
        }
    }
};
