/**
 * 1728. 猫和老鼠 II
 * https://leetcode-cn.com/problems/cat-and-mouse-ii/
 */

class Solution {
public:
    int cx, cy, mx, my, fx, fy;
    int win[1010][8][8][8][8][2]; // 1 cat win  2 mouse win
    int cj, mj;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    vector<string> G;
    int n, m;
    
    int dfs(int turn, int mx, int my, int cx, int cy, int who) {
        int &cache = win[turn][mx][my][cx][cy][who];
        //printf("dfs %d %d %d %d %d %d\n",turn,mx,my,cx,cy,who);
        if (cache != 0) return cache;
        if (turn == 100) return 1;
        if (mx == fx && my == fy) return cache = 2;
        if (cx == fx && cy == fy) return cache = 1;
        if (mx == cx && my == cy) return cache = 1;
        if (who == 0) { // mouse
            for (int dir=0;dir<4;dir++) {
                for (int i=0;i<=mj;i++) {
                    int nx, ny;
                    nx = mx + dx[dir] * i;
                    ny = my + dy[dir] * i;
                    if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) break;
                    if (G[nx][ny] == '#') break;
                    if (dfs(turn, nx, ny, cx, cy, 1) == 2) return cache = 2; 
                }
            }
            return cache = 1;
        } else { // cat
            for (int dir=0;dir<4;dir++) {
                for (int i=0;i<=cj;i++) {
                    int nx, ny;
                    nx = cx + dx[dir] * i;
                    ny = cy + dy[dir] * i;
                    if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) break;
                    if (G[nx][ny] == '#') break;
                    if (dfs(turn + 1, mx, my, nx, ny, 0) == 1) return cache = 1;
                }
            }
            return cache = 2;
        }
    }
    
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        G = grid;
        cj = catJump;
        mj = mouseJump;
        n = grid.size();
        m = grid[0].length();
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (grid[i][j] == 'C') cx = i, cy = j;
                if (grid[i][j] == 'M') mx = i, my = j;
                if (grid[i][j] == 'F') fx = i, fy = j;
            }
        }
        if (dfs(0, mx, my, cx, cy, 0) == 2) {
            return true;
        } else {
            return false;
        }
    }
};
