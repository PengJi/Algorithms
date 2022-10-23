class Solution {
public:
    // pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]
    // perf[i-1] = arr[0] ^ arr[1] ^ ... ^ arr[i-1]
    // arr[i] = perf[i] ^ perf[i-1];
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> res(n);
        res[0] = pref[0];

        for(int i = 1; i < n; i++) {
            res[i] = pref[i] ^ pref[i-1];
        }

        return res;
    }
};
