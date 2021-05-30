/**
 * 5773. 插入后的最大值
 * https://leetcode-cn.com/problems/maximum-value-after-insertion/
 */

class Solution {
public:
    string maxValue(string n, int x) {
        if (n[0] != '-') {
            int k = 0;
            while (k < n.size() && n[k] - '0' >= x) k ++ ;
            return n.substr(0, k) + to_string(x) + n.substr(k);
        } else {
            int k = 1;
            while (k < n.size() && n[k] - '0' <= x) k ++ ;
            return n.substr(0, k) + to_string(x) + n.substr(k);
        }
    }
};
