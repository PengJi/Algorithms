class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double res = 0, last = 0;
        for(auto& b : brackets) {
            res += b[1] * max(0.0, min(b[0], income) - last);
            last = b[0];
        }
        return res / 100;
    }
};
