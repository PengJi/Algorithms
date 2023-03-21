class Solution {
public:
    // 排序
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        const int m = score.size();

        vector<int> id(m);
        for (int i = 0; i < m; i++)
            id[i] = i;

        sort(id.begin(), id.end(), [&](int x, int y) {
            return score[x][k] > score[y][k];
        });

        vector<vector<int>> res(m);
        for (int i = 0; i < m; i++)
            res[i] = score[id[i]];

        return res;
    }
};
