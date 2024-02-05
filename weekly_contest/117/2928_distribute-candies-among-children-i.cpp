/**
 * 2928. 给小朋友们分糖果 I
 * https://leetcode.cn/problems/distribute-candies-among-children-i/description/
*/
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ans = 0;
        for (int i = 0; i <= limit; i++)
            for (int j = 0; j <= limit; j++)
                if (0 <= n - i - j && n - i - j <= limit)
                    ++ans;

        return ans;
    }
};
