/**
 * 6220. 可被三整除的偶数的平均值
 * https://leetcode.cn/problems/average-value-of-even-numbers-that-are-divisible-by-three/
*/

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int s = 0, c = 0;
        for(auto n: nums) {
            // 可被3整除的偶数等价于可被6整除
            if(n % 6 == 0) {
                s += n;
                c++;
            }
        }

        return c == 0 ? 0 : s/c;
    }
};
