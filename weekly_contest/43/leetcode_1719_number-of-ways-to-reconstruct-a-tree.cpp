/**
 * 1719. 重构一棵树的方案数
 * https://leetcode-cn.com/problems/number-of-ways-to-reconstruct-a-tree/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/number-of-ways-to-reconstruct-a-tree/solution/xiang-xi-fen-xi-liang-chong-jian-shu-si-eomax/
    int checkWays(vector<vector<int>>& pairs) {
        int maxn = 0;
        for(auto& p : pairs) maxn = max(maxn, max(p[0], p[1]));

        // 求出关系数,初始化关系矩阵(conn)
        int deg[maxn + 1], conn[maxn + 1][maxn + 1];
        memset(deg, 0, sizeof(deg));
        memset(conn, 0, sizeof(conn));
        for(auto& p : pairs) {
            conn[p[0]][p[1]] = conn[p[1]][p[0]] = 1;
            deg[p[0]]++, deg[p[1]]++;
        }

        // 求出实际点数 n
        int nodes[maxn + 1], n = 0;
        for(int i = 1; i <= maxn; ++i) if(deg[i]) nodes[n++] = i;

        // 按照 "关系数" 从大到小排序
        sort(nodes, nodes + n, [&](int a, int b) {
            return deg[a] > deg[b];
        });

        // 根节点必须是其它节点的祖先
        if(deg[nodes[0]] != n-1) return 0;

        // 寻找父节点 (fa) 和祖先节点 (all_fa)
        int fa[maxn + 1], all_fa[maxn + 1][maxn + 1];
        memset(fa, 0, sizeof(fa));
        memset(all_fa, 0, sizeof(all_fa));
        for(int i = 0; i < n; ++i) {
            for(int j = i-1; j >= 0; --j) {
                if(conn[nodes[i]][nodes[j]]) {
                    fa[nodes[i]] = nodes[j];
                    for(int f = fa[nodes[i]]; f; f = fa[f]) all_fa[nodes[i]][f] = 1;
                    break;
                }
            }
        }

        // 根据题目定义判断即可
        int res = 1;
        for(int i = 1; i <= maxn; ++i) {
            for(int j = i + 1; j <= maxn; ++j) {
                if(conn[i][j] && deg[i] == deg[j]) res = 2; // 判断是否有多个解
                if(conn[i][j] != (all_fa[i][j] || all_fa[j][i])) return 0; // 判断是否违反题目要求
            }
        }

        return res;
    }
};
