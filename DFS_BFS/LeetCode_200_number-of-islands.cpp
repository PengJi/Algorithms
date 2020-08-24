/**
 * 200. 岛屿数量
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。
 * 此外，你可以假设该网格的四条边均被水包围。
 * 
 * https://leetcode-cn.com/problems/number-of-islands/
 */

class Solution {
public:
    // 深度优先搜索
    // 时间复杂度：O(mn)
    // 空间复杂度：O(1)
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int row = grid.size();
        int col = grid[0].size();

        int ans = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == '1') {
                    removeIsland(grid, i, j);  // 修改值
                    ans++;
                }
            }
        }

        return ans;
    }

    void removeIsland(vector<vector<char>>& grid, int i, int j) {
        if(grid[i][j] == '0') return; 

        grid[i][j] = '0';  // 删除原值
        for(int k = 0; k < 4; k++) {  // 遍历四个方向
            int nx = i + dx[k];
            int ny = j + dy[k];

            if(nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size()) {
                removeIsland(grid, nx, ny);
            }
        }
    }

    // 广度优先搜索
    // 时间复杂度：O(mn)
    // 空间复杂度：O(mn)
    // 参考：https://leetcode-cn.com/problems/number-of-islands/solution/dfs-bfs-bing-cha-ji-python-dai-ma-java-dai-ma-by-l/
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = rows ? grid[0].size() :0 , islands = 0;
        if(rows == 0){
            return 0;
        }
        int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        vector<vector<bool>> marked(rows, vector<bool>(cols, false));
        queue<int> q; 

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(!marked[i][j] && grid[i][j] == '1'){
                    islands++;
                    q.push(i * cols + j);  // 将当前元素的坐标存入队列
                    marked[i][j] = true;

                    while(!q.empty()){
                        int curP = q.front();
                        q.pop();
                        int curX = curP / cols;
                        int curY = curP % cols;

                        // 遍历四个方向
                        for(int k = 0; k < 4; k++){
                            int newX = curX + directions[k][0];
                            int newY = curY + directions[k][1];
                            if(newX >= 0 && newX < rows && newY >= 0 && newY < cols && 
                                grid[newX][newY] == '1' && !marked[newX][newY]){
                                marked[newX][newY] = true;
                                q.push(newX * cols + newY);
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }

    // 并查集
    // 时间复杂度：
    // 空间复杂度：
    int numIslands(vector<vector<char>>& grid) {
        
    }
};
