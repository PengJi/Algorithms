/**
 * 5699. 从第一个节点出发到最后一个节点的受限路径数
 * https://leetcode-cn.com/problems/number-of-restricted-paths-from-first-to-last-node/
 */

//距离 节点号
typedef pair<int, int> PII;
const int N = 2e4 + 10, M = 8e4 + 10, MOD = 1e9 + 7;
int head[N], ver[M], nxt[M], edge[M], dist[N], op[N], cnt = 0, ans = 0;
bool vis[N];

class Solution {
public:
    // https://leetcode-cn.com/problems/number-of-restricted-paths-from-first-to-last-node/solution/dijkstra-dfs-by-raymond_yp-a3ab/
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        //初始化
        memset(dist, 0x3f, sizeof(dist));
        memset(vis, false, sizeof(vis));
        for(int i = 1; i <= n; i ++)
            op[i] = -1;
        memset(head, 0, sizeof(head));
        cnt = 0;
        ans = 0;
        
        
        //预处理边
        for(vector<int> &a : edges){
            add(a[0], a[1], a[2]);
            add(a[1], a[0], a[2]);
        }
        
        //求出最短路
        bfs(n);
        // for(int i = 1; i <= n; i ++)
        //     cout << i << " " << dist[i] << endl;
        
        //dfs求答案
        return dfs(1, n);
    }
    
    void add(int a, int b, int c){
        ver[++ cnt] = b;
        edge[cnt] = c;
        nxt[cnt] = head[a];
        head[a] = cnt;
    }
    
    void bfs(int n){
        dist[n] = 0;
        priority_queue<PII> Q;
        Q.push({0, n});
        
        while(!Q.empty()){
            int v = Q.top().second;
            Q.pop();
            if(vis[v])
                continue;
            vis[v] = true;
            for(int i = head[v]; i; i = nxt[i]){
                int u = ver[i];
                if(dist[u] > dist[v] + edge[i]){
                    dist[u] = dist[v] + edge[i];
                    Q.push({-dist[u], u});
                }
            }
        }
    }
    
    int dfs(int v, const int n){
        if(v == n){
            return 1;
        }
        //记忆化搜索
        if(op[v] != -1)
            return op[v];

        op[v] = 0;
        for(int i = head[v]; i; i = nxt[i]){
            int u = ver[i];
            if(dist[u] < dist[v])
                op[v] = (op[v] + dfs(u, n)) % MOD;
        }
        return op[v];
    }
};
