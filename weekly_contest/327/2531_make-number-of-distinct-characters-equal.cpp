class Solution {
public:
    // 暴力枚举
    bool isItPossible(string word1, string word2) {
        vector<int> c1(26, 0), c2(26, 0);

        for (char c : word1) c1[c - 'a']++;

        for (char c : word2) c2[c - 'a']++;

        int t1 = count(c1), t2 = count(c2);

        for (int i = 0; i < 26; i++) {
            if (c1[i] == 0)
                continue;

            for (int j = 0; j < 26; j++) {
                if (c2[j] == 0)
                    continue;

                if (--c1[i] == 0) --t1;
                if (++c1[j] == 1) ++t1;

                if (++c2[i] == 1) ++t2;
                if (--c2[j] == 0) --t2;

                if (t1 == t2)
                    return true;

                if (++c1[i] == 1) ++t1;
                if (--c1[j] == 0) --t1;

                if (--c2[i] == 0) --t2;
                if (++c2[j] == 1) ++t2;
            }
        }

        return false;
    }

    int count(const vector<int> &c) {
        int res = 0;

        for (int x : c)
            if (x > 0)
                res++;

        return res;
    }
};
