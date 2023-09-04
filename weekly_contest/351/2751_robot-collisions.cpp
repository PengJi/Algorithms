/**
 * 2751. 机器人碰撞
 * https://leetcode.cn/problems/robot-collisions/description/
*/

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths,
        string directions
    ) {
        const int n = positions.size();

        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int x, int y) {
            return positions[x] < positions[y];
        });

        stack<int> s;
        for (int i : id) {
            if (directions[i] == 'R') {
                s.push(i);

                continue;
            }

            while (!s.empty()) {
                if (healths[i] < healths[s.top()]) {
                    healths[i] = -1;
                    --healths[s.top()];

                    break;
                }

                if (healths[i] == healths[s.top()]) {
                    healths[i] = healths[s.top()] = -1;
                    s.pop();

                    break;
                }

                --healths[i];
                healths[s.top()] = -1;
                s.pop();
            }
        }

        vector<int> ans;
        for (int x : healths)
            if (x != -1)
                ans.push_back(x);

        return ans;
    }
};
