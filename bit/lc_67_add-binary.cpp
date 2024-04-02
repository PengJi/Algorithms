/**
 * 67. 二进制求和
 * https://leetcode-cn.com/problems/add-binary/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/add-binary/solution/er-jin-zhi-qiu-he-by-leetcode-solution/
    string addBinary(string a, string b) {
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int n = max(a.size(), b.size()), carry = 0;
        for (size_t i = 0; i < n; ++i) {
            carry += i < a.size() ? (a.at(i) == '1') : 0;
            carry += i < b.size() ? (b.at(i) == '1') : 0;
            ans.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }

        if (carry) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

class Solution {
public:
    string addBinary(string a, string b) {
        int len = max(a.size(), b.size());
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string res = "";
        int carry = 0;  // 关键点，存储进位
        for (int i = 0; i < len; i++) {
            if (i < a.size()) {
                carry += (a[i] == '1' ? 1 : 0);
            } else {
                carry += 0;
            }
            if (i < b.size()) {
                carry += (b[i] == '1' ? 1 : 0);
            } else {
                carry += 0;
            }

            res += (carry % 2 ? '1' : '0');
            carry /= 2;
        }
        if (carry) res += '1';

        reverse(res.begin(), res.end());
        return res;
    }
};
