/**
 * 38. 外观数列
 * https://leetcode-cn.com/problems/count-and-say/
 */

class Solution {
public:
    // 直接按照从 2 到 n 的顺序生成字符串，即每次找连续相同的数字段，合并。
    string countAndSay(int n) {
        string last = "1";
        for (int i = 2; i <= n; i++) {
            string gen = "";
            int count = 0;
            for (int j = 0; j < last.length(); j++) {
                count++;
                if (j == last.length() - 1 || last[j] != last[j + 1]) {
                    gen += to_string(count) + last[j];
                    count = 0;
                }
            }

            last = gen;
        }

        return last;
    }
};
