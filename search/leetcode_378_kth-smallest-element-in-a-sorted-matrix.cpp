/**
 * 378. 有序矩阵中第K小的元素
 * 
 * https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/
 */

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        long long l = -2e9, r = 2e9;
        int n = matrix.size();
        while (l < r) {
            long long mid = l + r >> 1;
            int cnt = 0, i = n - 1, j = 0;
            while (i >= 0 && j < n) {  // 统计矩阵中小于等于mid的元素个数
                if (matrix[i][j] <= mid) {
                    cnt += i + 1;
                    j ++;
                } else {
                    i --;
                }
            }
            if (cnt < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};