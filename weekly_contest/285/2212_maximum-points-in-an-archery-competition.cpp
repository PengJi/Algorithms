class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int n = aliceArrows.size();
        int maxScore = 0;
        vector<int> ans(n);
        /* 二进制枚举 */
        for (int i = 0; i < (1 << n); i++) {
            int usedArrows = 0;
            int curScore   = 0;
            vector<int> bobArrows(n);
            for (int j = 0; j < n; j++) {
                if (((i >> j) & 1) == 1) {
                    usedArrows += aliceArrows[j] + 1;  /* 使用的箭数 */
                    curScore   += j;                   /* 得分 */ 
                    bobArrows[j] = aliceArrows[j] + 1; /* 每一轮射中数 */
                }
            }
            /* 使用的总箭数有剩余, 且有更大值 */
            if (usedArrows <= numArrows && curScore > maxScore) {
                maxScore = curScore;
                ans = bobArrows;
                ans[0] += numArrows - usedArrows;
            }
        }
        return ans;
    }
};
