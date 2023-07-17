/**
 * 2709. 最大公约数遍历
 * https://leetcode.cn/problems/greatest-common-divisor-traversal
*/

const int N = 100000;

class Solution {
private:
    int f[N + 10];
    bool seen[N + 10], comp[N + 10];

    int find(int x) {
        return x == f[x] ? x : f[x] = find(f[x]);
    }

    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (f[fx] != fy)
            f[fx] = fy;
    }

public:
    bool canTraverseAllPairs(vector<int>& nums) {
        const int n = nums.size();

        // 预处理
        if (n == 1)
            return true;

        memset(seen, false, sizeof(seen));
        int m = 0;
        for (int i = 0; i < n; i++) {
            m = max(m, nums[i]);
            seen[nums[i]] = true;
        }

        if (seen[1])
            return false;

        for (int i = 2; i <= m; i++)
            f[i] = i;

        // 朴素筛求出所有数字的质因数，并合并集合
        memset(comp, false, sizeof(comp));
        for (int x = 2; x <= m; x++) {
            if (comp[x])
                continue;

            for (int y = x + x; y <= m; y += x) {
                comp[y] = true;
                if (seen[y])
                    merge(x, y);
            }
        }

        // 判断所有数字是否都在一个集合中
        for (int i = 1; i < n; i++)
            if (find(nums[i]) != find(nums[0]))
                return false;

        return true;
    }
};
