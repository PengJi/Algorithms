/**
 * 773. 滑动谜题
 * https://leetcode.cn/problems/sliding-puzzle/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/sliding-puzzle/solution/bfskuang-jia-miao-sha-ge-chong-yi-zhi-you-xi-by-la/
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = 2, n = 3;
        string start = "";
        string target = "123450";
        // 将 2x3 的数组转化成字符串
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                start.push_back(board[i][j] + '0');
            }
        }
        // 记录一维字符串的相邻索引
        vector<vector<int>> neighbor = {
            {1, 3},
            {0, 4, 2},
            {1, 5},
            {0, 4},
            {3, 1, 5},
            {4, 2}};

        /******* BFS 算法框架开始 *******/
        queue<string> q;
        unordered_set<string> visited;
        q.push(start);
        visited.insert(start);

        int step = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front();
                q.pop();
                // 判断是否达到目标局面
                if (target == cur) {
                    return step;
                }
                // 找到数字 0 的索引
                int idx = 0;
                for (; cur[idx] != '0'; idx++)
                    ;
                // 将数字 0 和相邻的数字交换位置
                for (int adj : neighbor[idx]) {
                    string new_board = cur;
                    swap(new_board[adj], new_board[idx]);
                    // 防止走回头路
                    if (!visited.count(new_board)) {
                        q.push(new_board);
                        visited.insert(new_board);
                    }
                }
            }
            step++;
        }
        return -1;
        /******* BFS 算法框架结束 *******/
    }
};

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        typedef vector<vector<int>> VII;
        VII target = {{1, 2, 3}, {4, 5, 0}};
        if (board == target) return 0;
        queue<VII> q;
        q.push(board);
        map<VII, int> dist;
        dist[board] = 0;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

        while (q.size()) {
            auto t = q.front();
            q.pop();

            int x, y;
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 3; j++)
                    if (t[i][j] == 0)
                        x = i, y = j;
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a >= 0 && a < 2 && b >= 0 && b < 3) {
                    auto r = t;
                    swap(r[x][y], r[a][b]);
                    if (!dist.count(r)) {
                        dist[r] = dist[t] + 1;
                        if (r == target) return dist[r];
                        q.push(r);
                    }
                }
            }
        }
        return -1;
    }
};
