/**
 * 22. 括号生成
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * https://leetcode-cn.com/problems/generate-parentheses/
 */

class Solution {
public:
    // dfs
    // 思路：https://leetcode-cn.com/problems/generate-parentheses/solution/hui-su-suan-fa-by-liweiwei1419/
    // 时间复杂度：
    // 空间复杂度：
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
