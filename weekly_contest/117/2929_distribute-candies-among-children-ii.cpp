/**
 * 2929. 给小朋友们分糖果 II
 * https://leetcode.cn/problems/distribute-candies-among-children-ii/description/
*/
#define LL long long

class Solution {
public:
    LL distributeCandies(int n, int limit) {
        LL ans = 0;
        for (int i = min(n, limit); i >= 0; i--) {
            if (n - i <= limit)
                ans += n - i + 1;
            else
                ans += max(0, limit - (n - i - limit) + 1);
        }

        return ans;
    }
};

作者：wzc1995
链接：https://www.acwing.com/solution/content/214449/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。