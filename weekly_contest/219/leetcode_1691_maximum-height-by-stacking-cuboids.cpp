/**
 * 1691. 堆叠长方体的最大高度
 * https://leetcode-cn.com/problems/maximum-height-by-stacking-cuboids/
 */

class Solution {
public:
    // 动态规划
    // https://leetcode-cn.com/problems/maximum-height-by-stacking-cuboids/solution/dui-die-chang-fang-ti-de-zui-da-gao-du-b-qzgy/
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for (auto& cubic: cuboids) {
            sort(cubic.begin(), cubic.end());
        }
        
        // 保证枚举关系拓扑性的排序都可以
        // sort(cuboids.begin(), cuboids.end());
        sort(cuboids.begin(), cuboids.end(), [](const auto& u, const auto& v) {
            return pair(u[2], u[0] + u[1]) < pair(v[2], v[0] + v[1]);
        });
        
        vector<int> f(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (cuboids[j][0] <= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {
                    f[i] = max(f[i], f[j]);
                }
            }
            f[i] += cuboids[i][2];
        }
        
        return *max_element(f.begin(), f.end());
    }
};
