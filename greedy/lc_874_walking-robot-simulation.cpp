/**
 * 874. 模拟行走机器人
 * https://leetcode-cn.com/problems/walking-robot-simulation/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/walking-robot-simulation/solution/tu-jie-mo-ni-xing-zou-ji-qi-ren-by-dekeshile/
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        /*
            ( 0,  1)  -- 北：x不动，y向上一步
            ( 0, -1)  -- 南：x不动，y向下一步
            ( 1,  0)  -- 东：y不动，x向右一步
            (-1,  0)  -- 西：y不动，x向左一步
        */
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0, direction = 0;  // 方向初始化为北

        // 障碍物集合: 后续每走一步，都判断是否与障碍物坐标点相同，如果相同，则不继续移动，读取下一条指令
        unordered_map<int, unordered_set<int>> obs;
        for (auto& iter : obstacles)
            obs[iter[0]].insert(iter[1]);

        int ans = 0;
        for (auto& cmd : commands) {
            if (cmd == -1) {
                direction = (direction + 1) % 4;  // 向右转
            } else if (cmd == -2) {
                direction = (direction + 3) % 4;  //向左转
            } else {                              // 在当前方向上，移动相应步长
                for (int i = 0; i < cmd; ++i) {
                    int nx = x + dx[direction];
                    int ny = y + dy[direction];
                    auto iter = obs.find(nx);
                    if (iter == obs.end() || iter->second.find(ny) == iter->second.end()) {
                        x = nx;
                        y = ny;  // 如果没遇到障碍物，则向前移动一步
                        ans = max(ans, x * x + y * y);
                    }
                }
            }
        }
        return ans;
    }
};
