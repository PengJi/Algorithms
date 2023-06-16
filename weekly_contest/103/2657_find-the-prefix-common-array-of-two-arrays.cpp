/**
 * 2657. 找到两个数组的前缀公共数组
 * https://leetcode.cn/problems/find-the-prefix-common-array-of-two-arrays/
*/
class Solution {
public:
    // 哈希表
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        const int n = A.size();

        vector<bool> s1(n + 1, false), s2(n + 1, false);
        vector<int> ans(n);

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            s1[A[i]] = true;
            s2[B[i]] = true;

            if (s1[B[i]]) ++cnt;
            if (s2[A[i]]) ++cnt;
            if (A[i] == B[i]) --cnt;

            ans[i] = cnt;
        }

        return ans;
    }
};
