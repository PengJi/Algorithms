/**
 * 17. 电话号码的字母组合
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/solution/dian-hua-hao-ma-de-zi-mu-zu-he-by-leetcode-solutio/
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if (digits.empty()) {
            return combinations;
        }
        unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string combination;
        backtrack(combinations, phoneMap, digits, 0, combination);
        return combinations;
    }

    void backtrack(vector<string>& combinations, const unordered_map<char, string>& phoneMap, const string& digits, int index, string& combination) {
        if (index == digits.length()) {
            combinations.push_back(combination);
        } else {
            char digit = digits[index];
            const string& letters = phoneMap.at(digit);
            for (const char& letter: letters) {
                combination.push_back(letter);
                backtrack(combinations, phoneMap, digits, index + 1, combination);
                combination.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<string> res;
    string strs[10] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz",
    };

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return res;
        dfs(digits, 0, "");
        return res;
    }

    void dfs(string& digits, int idx, string path) {
        if(idx == digits.size()) res.push_back(path);
        else {
            for(auto c: strs[digits[idx] - '0']) {
                dfs(digits, idx + 1, path + c);  // 包含回溯，下面解法为完整的回溯过程
            }
        }
    }
};

class Solution {
public:
    vector<string> ans;
    string path;
    string strs[10] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz",
    };

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ans;
        dfs(digits, 0);
        return ans;
    }

    void dfs(string& digits, int idx) {
        if (path.size() == digits.size()) {
            ans.push_back(path);
            return;
        }

        for (auto c : strs[digits[idx] - '0']) {
            path.push_back(c);
            dfs(digits, idx + 1);
            path.pop_back();
        }
    }
};
