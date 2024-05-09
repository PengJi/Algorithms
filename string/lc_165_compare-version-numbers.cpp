/**
 * 165. 比较版本号
 * https://leetcode-cn.com/problems/compare-version-numbers/
 */

class Solution {
public:
    // 双指针
    int compareVersion(string version1, string version2) {
        int len1 = version1.size(), len2 = version2.size();
        int i = 0, j = 0;
        int x, y;

        while (i < len1 || j < len2) {
            x = 0;
            while (i < len1 && version1[i] != '.') {
                x = x * 10 + (version1[i] - '0');
                i++;
            }
            i++;  // 跳过 .

            y = 0;
            while (j < len2 && version2[j] != '.') {
                y = y * 10 + (version2[j] - '0');
                j++;
            }
            j++;  // 跳过 .

            if (x != y) {
                return x > y ? 1 : -1;
            }
        }

        return 0;
    }
};
