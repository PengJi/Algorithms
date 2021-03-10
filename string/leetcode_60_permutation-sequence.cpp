/**
 * 60. 排列序列
 * https://leetcode-cn.com/problems/permutation-sequence/
 */

class Solution {
public:
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(1)
    string getPermutation(int n, int k) {
        string ans;
        vector<bool> vt(10);  // 是否用过
        for(int i = 0; i < n; i++) {
            int fact = 1;
            for(int j = 1; j <= n-i-1; j++) fact *= j;  // 计算全排列的数目

            // 依次确定高位
            for(int j = 1; j <= n; j++) {
                if(!vt[j]) {
                    if(fact < k) {
                        k -= fact;
                    } else {
                        ans += to_string(j);
                        vt[j] = true;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};
