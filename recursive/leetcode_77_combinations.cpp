class Solution {
public:
    // 回溯法
    // 时间复杂度：
    // 空间复杂度：O(Cnk)
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(1, tmp, n, k, res);

        return res;
    }

    void backtrack(int first, vector<int>& vec, int n, int k, vector<vector<int>>& res){
        if(vec.size() == k){
            res.push_back(vec);
            return;
        }

        for(int i = first; i < n+1; i++){
            vec.push_back(i);
            backtrack(i+1, vec, n, k, res);
            vec.pop_back();
        }
    }
};