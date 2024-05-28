/**
 * 60. 排列序列
 * https://leetcode-cn.com/problems/permutation-sequence/
 */

class Solution {
public:
    // 从高位到低位依次确定每一位
    // 对于每一位，从小到大依次枚举未使用过的数，确定当前位
    // https://www.acwing.com/solution/content/145/
    string getPermutation(int n, int k) {
        string res;

        // 表示当前位是否用过
        vector<bool> vec(n);

        // 从高位到低位依次确定每一位
        for (int i = 0; i < n; i++) {
            // 求阶乘
            int f = 1;
            for (int j = 1; j < n - i; j++) f *= j;  // 计算全排列的数目

            // 从小到大枚举未使用过的数
            for (int j = 0; j < n; j++) {
                if (!vec[j]) {     // 如果当前为没有被使用过
                    if (k <= f) {  // 可以确定一位
                        res += to_string(j + 1);
                        vec[j] = true;
                        break;
                    }

                    k -= f;  // 剩余第几位
                }
            }
        }

        return res;
    }
};
