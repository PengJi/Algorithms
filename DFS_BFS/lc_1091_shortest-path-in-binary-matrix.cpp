/**
 * 1091. 二进制矩阵中的最短路径
 * https://leetcode.cn/problems/shortest-path-in-binary-matrix/
 */

class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

    // https://leetcode-cn.com/problems/shortest-path-in-binary-matrix/solution/cbiao-zhun-de-bfs-by-mei-you-ni-de-liu-yue-tian/
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)return -1;
        int n=grid.size();
        queue<pair<int,int>>q;
        q.push(make_pair(0,0));
        int length=1;
        grid[0][0]=2;   //将访问过的点标记为2
        while(!q.empty()){
            int l=q.size();      //遍历当前队列所有的元素
            for(int i=0;i<l;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x==n-1&&y==n-1)return length;
                for(int j=0;j<8;j++){    
                    int x1=x+dir[j][0];
                    int y1=y+dir[j][1];
                    if(x1<0||y1<0||x1>=n||y1>=n||grid[x1][y1])continue;  //越界或者不满足访问条件跳过
                    grid[x1][y1]=2;
                    q.push(make_pair(x1,y1));
                }
            }
            length++;
        }
        
        return -1;
    }
};

#define x first
#define y second

typedef pair<int, int> PII;

class Solution {
public:
    // 宽度优先搜索
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        if (g[0][0]) return -1;
        int n = g.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));
        dist[0][0] = 1;
        queue<PII> q;
        q.push({0, 0});

        int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        while (q.size()) {
            auto t = q.front();
            q.pop();

            for (int i = 0; i < 8; i ++ ) {
                int x = t.x + dx[i], y = t.y + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < n && g[x][y] == 0 && dist[x][y] == -1) {
                    dist[x][y] = dist[t.x][t.y] + 1;
                    q.push({x, y});
                }
            }
        }

        return dist[n - 1][n - 1];
    }
};
