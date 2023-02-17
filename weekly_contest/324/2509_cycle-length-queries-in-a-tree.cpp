class Solution {
public:
    int get_depth(int x) {
        int res = 0;
        while (x) {
            x >>= 1;
            res ++ ;
        }
        return res;
    }

    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        for (auto& q: queries) {
            int a = q[0], b = q[1];
            if (a > b) swap(a, b);
            int da = get_depth(a), db = get_depth(b);

            int len = 0;
            for (int i = 0; i < db - da; i ++ ) {
                b >>= 1;
                len ++ ;
            }

            while (a != b) {
                a >>= 1, b >>= 1;
                len += 2;
            } 
            res.push_back(len + 1);
        }

        return res;
    }
};
