/**
 * 165. 比较版本号
 * https://leetcode-cn.com/problems/compare-version-numbers/
 */

class Solution {
public:
    // https://www.acwing.com/activity/content/code/content/411120/
    int compareVersion(string version1, string version2) {
        int len1 = version1.size(), len2 = version2.size();
        for(int i = 0, j = 0; i < len1 || j < len2;) {
            int a = i, b = j;
            while(a < len1 && version1[a] != '.') a++;
            while(b < len2 && version2[b] != '.') b++;
            int x = a == i ? 0 : stoi(version1.substr(i, a - i));
            int y = b == j ? 0 : stoi(version2.substr(j, b - j));
            if(x > y) return 1;
            if(x < y) return -1;
            i = a + 1;
            j = b + 1;
        }

        return 0;
    }
};
