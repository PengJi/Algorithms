class Solution {
public:
    typedef pair<int, int> pii;
    
    // 注意参数带 &，不然超时
    bool check(vector<int> &a, set<pii> &p) {
        for(int i = a[0]; i <= a[2]; i++) {
            for(int j = a[1]; j <= a[3]; j++) {
                if(p.count(pii(i, j)) < 1) return false;
            }
        }

        return true;
    }

    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int res = 0;
        set<pii> st;
        for(auto &d : dig) st.insert(pii(d[0], d[1]));
        for(auto &a : artifacts) {
            if(check(a, st)) res++;
        }

        return res;
    }
};
