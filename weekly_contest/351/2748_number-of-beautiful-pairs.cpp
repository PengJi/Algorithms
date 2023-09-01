/**
 * 2748. 美丽下标对的数目
 * https://leetcode.cn/problems/number-of-beautiful-pairs/description/
*/

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        const int n = nums.size();
        int c[10];
        memset(c, 0, sizeof(c));

        bool v[10][10];
        memset(v, 0, sizeof(v));
        for (int i = 1; i < 10; i++)
            for (int j = i; j < 10; j++)
                if (gcd(i, j) == 1)
                    v[i][j] = v[j][i] = true;

        int ans = 0;
        for (int x : nums) {
            int r = x % 10;
            for (int i = 1; i < 10; i++)
                if (v[i][r])
                    ans += c[i];

            while (x >= 10)
                x /= 10;
            ++c[x];
        }

        return ans;
    }
};
