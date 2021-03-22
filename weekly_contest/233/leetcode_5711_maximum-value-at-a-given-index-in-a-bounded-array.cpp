/**
 * 5711. 有界数组中指定下标处的最大值
 * https://leetcode-cn.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
 */

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int res = 1;
        int left = index, right = index;
        int rest = maxSum - n;
        int len;
        while(left > 0 || right < n-1) {
            len = right - left + 1;
            if(rest >= len) {
                rest -= len;
                res++;
                left = max(0, left-1);
                right = min(n-1, right+1);
            } else {
                break;
            }
        }

        res += rest/n;

        return res;
    }
};
