/**
 * 6221. 最流行的视频创作者
 * https://leetcode.cn/problems/most-popular-video-creator/
*/

class Solution {
public:
    typedef long long LL;  // 注意：数据范围为 10^5，相加可能会超 int，所以需要 long long 

    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, LL> ss;  // 创作者，总播放量
        unordered_map<string, vector<int>> si;  // 创作者，视频id

        LL m = 0;
        int len = creators.size();

        // 统计每个创作者
        for(int i = 0; i < len; i++) {
            ss[creators[i]] += views[i];
            si[creators[i]].push_back(i);
        }

        // 求最大值
        for(auto& [k, v]: ss) {
            if(v > m) m = v;
        }

        vector<vector<string>> res;
        for(auto& [k, v]: ss) {
            if(v == m) {
                string id;
                int mv = -1;
                for(auto x: si[k]) {  // 寻找最小的 id
                    if(views[x] > mv) {
                        mv = views[x];
                        id = ids[x];
                    } else if(views[x] == mv) {
                        id = min(id, ids[x]);
                    }
                }

                res.push_back({k, id});
            }
        }

        return res;
    }
};
