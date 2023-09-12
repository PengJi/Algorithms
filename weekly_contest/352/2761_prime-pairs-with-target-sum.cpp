/**
 * 2761. 和等于目标值的质数对
 * https://leetcode.cn/problems/prime-pairs-with-target-sum/description/
*/

class Solution {
public:       
    vector<vector<int>> findPrimePairs(int n) {
        vector<int> prime;
        vector<bool> v(n + 1, false);

        v[1] = true;
        for (int i = 2; i <= n / 2; i++) { // 这里枚举到 n/2 就行，[n/2+1, n] 会被筛走。
            if (!v[i])
                prime.push_back(i);

            for (int p : prime) {
                if (i * p > n)
                    break;

                v[i * p] = true;
                if (i % p == 0)
                    break;
            }
        }

        vector<vector<int>> ans;
        for (int x : prime)
            if (!v[n - x])
                ans.push_back({x, n - x});

        return ans;
    }
};
