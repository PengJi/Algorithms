class Solution {
public:
    string removeStars(string s) {
        string res;
        for(auto x: s) {
            if(x == '*') res.pop_back();
            else res += x;
        }

        return res;
    }
};
