class Solution {
public:

    void replace(vector<int> &s, int x, int y) {
        for (int i = 0; i < s.size(); i++)
            if (s[i] == x)
                s[i] = y;
    }

    int get_num(const vector<int> &s) {
        int res = 0;

        for (int i = s.size() - 1; i >= 0; i--)
            res = res * 10 + s[i];

        return res;
    }

    int find_max(vector<int> s) {
        int p = -1;
        for (int i = s.size() - 1; i >= 0; i--)
            if (s[i] != 9) {
                p = i;

                break;
            }

        if (p != -1) 
            replace(s, s[p], 9);

        return get_num(s);
    }

    int find_min(vector<int> s) {
        replace(s, s.back(), 0);

        return get_num(s);
    }

    // 贪心
    int minMaxDifference(int num) {
        vector<int> s;

        while (num) {
            s.push_back(num % 10);
            num /= 10;
        }

        return find_max(s) - find_min(s);
    }
};
