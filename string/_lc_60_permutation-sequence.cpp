/**
 * 60. 排列序列
 * https://leetcode-cn.com/problems/permutation-sequence/
 */

class Solution {
public:
    // https://www.acwing.com/solution/content/145/
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(1)
    string getPermutation(int n, int k) {
        string ans;
        vector<bool> vt(10);  // 是否用过
        for(int i = 0; i < n; i++) {
            int fact = 1;
            for(int j = 1; j <= n-i-1; j++) fact *= j;  // 计算全排列的数目

            // 依次确定高位
            for(int j = 1; j <= n; j++) {
                if(!vt[j]) {
                    if(fact < k) {
                        k -= fact;
                    } else {
                        ans += to_string(j);
                        vt[j] = true;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};

class Solution {
public:
    // 从高位到低位依次确定每一位
    // 对于每一位，从小到大依次枚举未使用过的数，确定当前位
    string getPermutation(int n, int k) {
        string res;

        // 表示当前位是否用过
        vector<bool> vec(n);

        // 从高位到低位依次确定每一位
        for(int i = 0; i < n; i++) {
            // 求阶乘
            int f = 1;
            for(int j = 1; j < n - i; j++) f *= j;

            // 从小到大枚举未使用过的数
            for(int j = 0; j < n; j++) {
                if(!vec[j]) {  // 如果当前为没有被使用过
                    if(k <= f) {  // 可以确定一位
                        res += to_string(j+1);
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
