/**
 * 28. 实现 strStr()
 * https://leetcode-cn.com/problems/implement-strstr/
 */

class Solution {
public:
    // 双指针遍历
    // 时间复杂度：最坏时间复杂度为 O((m-n)n)，最优时间复杂度为 O(m)
    // 空间复杂度：O(1)
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if(n == 0) return 0;
        for(int i = 0; i <= m-n; i++) {
            for(int j = 0; j < n; j++) {
                if(haystack[i+j] != needle[j]) break;
                if(j == n-1) return i;
            }
        }

        return -1;
    }
};
