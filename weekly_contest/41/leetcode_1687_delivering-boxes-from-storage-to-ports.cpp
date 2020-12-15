/**
 * 1687. 从仓库到码头运输箱子
 * https://leetcode-cn.com/problems/delivering-boxes-from-storage-to-ports/
 */

class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
int n = boxes.size();
        vector<int> L(n);
        for(int i = n - 1, j = n - 1, sumB = 0, sumW = 0; i >= 0; i -= 1){
            while(j >= 0 and sumB + 1 <= maxBoxes and sumW + boxes[j][1] <= maxWeight){
                sumB += 1;
                sumW += boxes[j][1];
                j -= 1;
            }
            L[i] = j;
            sumB -= 1;
            sumW -= boxes[i][1];
        }
        vector<int> pre(n);
        for(int i = 1; i < n; i += 1)
            pre[i] = pre[i - 1] + (boxes[i][0] != boxes[i - 1][0]);
        vector<int> dp(n);
        multiset<int> s;
        s.insert(0);
        for(int i = 0, j = -1; i < n; i += 1){
            while(j < L[i]){
                if(j == - 1) s.erase(s.find(0));
                else s.erase(s.find(dp[j] - (j + 1 < n ? pre[j + 1] : 0)));
                j += 1;
            }
            dp[i] = *s.begin() + pre[i] + 2;
            s.insert(dp[i] - (i + 1 < n ? pre[i + 1] : 0));  
        }
        return dp.back();
    }
};
