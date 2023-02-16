typedef long long LL;

class Solution {
public:
    LL get(int a, int b) {
        if (a > b) swap(a, b);
        return a * 1000000ll + b;
    }

    // 图论
    bool isPossible(int n, vector<vector<int>>& edges) {
        unordered_set<LL> hash;
        vector<int> d(n + 1);
        for (auto& e: edges) {
            int a = e[0], b = e[1];
            d[a] ++, d[b] ++ ;
            hash.insert(get(a, b));
        }

        vector<int> vs;
        for (int i = 1; i <= n; i ++ )
            if (d[i] % 2)
                vs.push_back(i);

        if (vs.size() == 0) return true;
        else if (vs.size() == 2) {
            int a = vs[0], b = vs[1];
            if (!hash.count(get(a, b))) return true;
            for (int i = 1; i <= n; i ++ )
                if (a != i && b != i && !hash.count(get(a, i)) && !hash.count(get(b, i)))
                    return true;
        } else if (vs.size() == 4) {
            for (int i = 0; i < 24; i ++ ) {
                int a = vs[0], b = vs[1], c = vs[2], d = vs[3];
                if (!hash.count(get(a, b)) && !hash.count(get(c, d)))
                    return true;
                next_permutation(vs.begin(), vs.end());
            }
        }

        return false;
    }
};
