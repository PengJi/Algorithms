class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int res = 0;
        string op = "GMP";
        for(auto x : op) {
            int d = 0;
            for(int i = 0; i < garbage.size(); i++) {
                int cnt = 0;
                for(auto n : garbage[i]) {
                    if(n == x) cnt++;
                }
                if(cnt) d = i;
                res += cnt;
            }
            for(int i = 0; i < d; i++) {
                res += travel[i];
            }
        }

        return res;
    }
};
