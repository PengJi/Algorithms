/**
 * 363. 矩形区域不超过 K 的最大数值和
 * https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/
 */

class Solution {
public:
    // https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/discuss/851448/C%2B%2B-from-800-ms-to-50-ms
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int res = INT_MIN, rows = matrix.size(), cols = matrix[0].size();
        for (int l = 0; l < cols; ++l) {
            vector<int> sums(rows);
            for (int r = l; r < cols; ++r) {
                int kadane = 0, max_kadane = INT_MIN;
                for (int i = 0; i < rows; ++i) {
                    sums[i] += matrix[i][r];
                    kadane = max(kadane + sums[i], sums[i]);
                    max_kadane = max(max_kadane, kadane);
                }
                if (max_kadane <= k) {
                    res = max(res, max_kadane);
                    continue;
                }
                set<int> s = {0};
                int run_sum = 0;
                for (int sum : sums) {
                    run_sum += sum;
                    auto it = s.lower_bound(run_sum - k);
                    if (it != end(s))
                        res = max(res, run_sum - *it);
                    s.insert(run_sum);
                }
            }
        }
        return res;
    }
};
