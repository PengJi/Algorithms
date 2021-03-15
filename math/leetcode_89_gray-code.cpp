/**
 * 89. 格雷编码
 * https://leetcode-cn.com/problems/gray-code/
 */

class Solution {
public:
    // https://www.acwing.com/solution/content/171/
    // O(2^n)
    // O（1)
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        int t = 0;
        while (n--){
            int n = res.size();
            for (int i = n - 1; i >= 0; i --) {
                res.push_back(res[i] + (1 << t));
            }
            t += 1;
        }
        
        return res;
    }
};
