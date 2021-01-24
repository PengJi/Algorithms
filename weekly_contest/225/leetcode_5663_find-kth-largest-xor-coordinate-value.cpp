/**
 * 5663. 找出第 K 大的异或坐标值
 * https://leetcode-cn.com/problems/find-kth-largest-xor-coordinate-value/
 */

class Solution {
public:
    // 前缀和
    // https://leetcode-cn.com/problems/find-kth-largest-xor-coordinate-value/solution/ctu-jie-si-lu-fen-xi-shuang-bai-jie-fa-b-x93t/
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(i == 0 && j == 0) 
                    matrix[i][j] = matrix[i][j];
                else if(i == 0) 
                    matrix[i][j] = matrix[i][j-1] ^ matrix[i][j];
                else if(j == 0)
                    matrix[i][j] = matrix[i-1][j] ^ matrix[i][j];
                else
                    matrix[i][j] = matrix[i][j-1] ^ matrix[i-1][j] ^ matrix[i-1][j-1] ^ matrix[i][j];

                if(pq.size() < k) 
                    pq.push(matrix[i][j]);
                else {
                    if(matrix[i][j] > pq.top()) {
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }

            }
        }

        return pq.top();
    }
};
