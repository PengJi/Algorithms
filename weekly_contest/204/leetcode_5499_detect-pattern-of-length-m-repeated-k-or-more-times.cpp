/**
 * 5499. 重复至少 K 次且长度为 M 的模式
 * https://leetcode-cn.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/
 */

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        for (int i = 0; i + m * k <= n; ++i) {
            bool check = true;
            for (int j = i + m; j < i + m * k; ++j) {
                if (arr[j] != arr[j - m]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                return true;
            }
        }
        return false;
    }
};
