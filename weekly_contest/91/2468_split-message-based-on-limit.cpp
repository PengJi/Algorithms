class Solution {
public:
    int get(int k, int limit) {
        int len = to_string(k).size();
        int res = (limit - 3 - len) * k;
        int s = 0;
        for (int i = 1, t = 9; i < len; i ++, t *= 10) {
            res -= i * t;
            s += t;
        }
        res -= len * (k - s);
        return res;
    }

    vector<string> splitMessage(string message, int limit) {
        int n = message.size();
        for (int i = 1; i <= n; i ++ ) {
            if (get(i, limit) >= n) {
                vector<string> res;

                for (int j = 1, k = 0; j <= i && k < n; j ++ ) {
                    string str = "<" + to_string(j) + "/" + to_string(i) + ">";
                    int len = min(n - k, limit - (int)str.size());
                    res.push_back(message.substr(k, len) + str);
                    k += len;
                }

                return res;
            }
        }

        return {};
    }
};
