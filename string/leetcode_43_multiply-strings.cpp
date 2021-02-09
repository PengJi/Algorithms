/**
 * 43. 字符串相乘
 * https://leetcode-cn.com/problems/multiply-strings/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/multiply-strings/solution/you-hua-ban-shu-shi-da-bai-994-by-breezean/
    // 时间复杂度：O(mn)
    // 空间复杂度：O(m+n)
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";

        int len1 = num1.size(), len2 = num2.size();
        vector<int> res(len1 + len2);  // 将每位的结果放入数组
        int n1, n2, sum;
        for(int i = len1 - 1; i >= 0; i--) {
            n1 = num1[i] - '0';
            for(int j = len2 - 1; j >= 0; j--) {
                n2 = num2[j] - '0';
                sum = res[i+j+1] + n1 * n2;
                res[i+j+1] = sum % 10;  // 确定每位的值
                res[i+j] += sum / 10;  //进位
            }
        }

        string ans = "";
        // 转为字符串
        for(int i = 0; j < res.size(); i++) {
            if(i == 0 && res[i] == 0) continue;  // 首位为0
            ans += to_string(res[i]); 
        }

        return ans;
    } 
};
