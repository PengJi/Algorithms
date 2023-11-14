/**
 * 2844. 生成特殊数字的最少操作
 * https://leetcode.cn/problems/minimum-operations-to-make-a-special-number/description/
*/
class Solution {
public:
    int minimumOperations(string num) {
        int p0 = -1, p5 = -1;
        for (int i = num.size(); i >= 0; i--) {
            if (num[i] == '0') {
                if (p0 != -1)
                    return num.size() - i - 2;
                p0 = i;
            } else if (num[i] == '5') {
                if (p0 != -1)
                    return num.size() - i - 2;
                p5 = i;
            } else if (num[i] == '2' || num[i] == '7') {
                if (p5 != -1)
                    return num.size() - i - 2;
            }
        }

        if (p0 != -1)
            return num.size() - 1;

        return num.size();
    }
};
