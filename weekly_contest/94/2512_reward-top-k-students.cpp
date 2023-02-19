/**
 * 2512. 奖励最顶尖的 K 名学生
 * https://leetcode.cn/problems/reward-top-k-students/description/
*/

class Solution {
public:
    // 哈希表
    vector<int> topStudents(vector<string>& posf, vector<string>& negf, 
        vector<string>& rp, vector<int>& sid, int k
    ) {
        unordered_set<string> pos(posf.begin(), posf.end());
        unordered_set<string> neg(negf.begin(), negf.end());

        const int n = rp.size();
        unordered_map<int, int> score;

        for (int i = 0; i < n; i++) {
            const int m = rp[i].size();

            string w;
            for (int j = 0; j <= m; j++) {
                if (j < m && rp[i][j] != ' ') {
                    w += rp[i][j];

                    continue;
                }

                if (pos.find(w) != pos.end())
                    score[sid[i]] += 3;
                else if (neg.find(w) != neg.end())
                    score[sid[i]]--;

                w.clear();
            }
        }

        sort(sid.begin(), sid.end(), [&](int x, int y) {
            if (score[x] != score[y])
                return score[x] > score[y];

            return x < y;
        });

        sid.resize(k);

        return sid;
    }
};
