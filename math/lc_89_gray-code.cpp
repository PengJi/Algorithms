/**
 * 89. 格雷编码
 * https://leetcode.cn/problems/gray-code/
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


class Solution {
public:
    // 思路比较巧妙
    // 将后一半与前一半对称，然后后一半的每位数加一
    vector<int> grayCode(int n) {
        vector<int> res(1, 0);
        while(n--) {
            for(int i = res.size()-1; i >= 0; i--) {
                res[i] *= 2;  // 相当于左移一位
                res.push_back(res[i] + 1);  // 最末位加1
            }
        }

        return res;
    }
};
