/**
 * 43. 字符串相乘
 * https://leetcode-cn.com/problems/multiply-strings/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/multiply-strings/solution/you-hua-ban-shu-shi-da-bai-994-by-breezean/
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") {
            return "0";
        }

        int len1 = num1.size(), len2 = num2.size();
        vector<int> res(len1+len2);
        for(int i = len1-1; i >= 0; i--) {
            int n1 = num1[i] - '0';
            for(int j = len2-1; j >= 0; j--) {
                int n2 = num2[j] - '0';
                int sum = (res[i+j+1] + n1 * n2);
                res[i+j+1] = sum % 10;
                res[i+j] += sum / 10;
            }
        }

        string ans = "";
        for(int i = 0; i < res.size(); i++) {
            if(i == 0 && res[i] == 0) continue;
            ans += to_string(res[i]);
        }

        return ans;
    }
};
