/**
 * 2660. 保龄球游戏的获胜者
 * https://leetcode.cn/problems/determine-the-winner-of-a-bowling-game/
*/
class Solution {
public:
    int isWinner(vector<int>& p1, vector<int>& p2) {
        int a = cal(p1), b = cal(p2);
        if (a > b) return 1;
        if (a < b) return 2;
        return 0;
    }
    int cal(vector<int>& p) {
        int n = p.size();
        int sum = 0;
        for (int i = 0; i < n; i ++) {
            if ((i - 1 >= 0 and p[i - 1] == 10) || (i - 2 >= 0 and p[i - 2] == 10)) sum += 2 * p[i];
            else sum += p[i];
        }
        return sum;
    }
};
