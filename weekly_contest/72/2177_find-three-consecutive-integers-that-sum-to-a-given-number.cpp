class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> res;
        if(num % (long long)3 == 0) {
            long long tmp = num / (long long)3;
            res.push_back(tmp - 1);
            res.push_back(tmp);
            res.push_back(tmp + 1);
        }
        
        return res;
    }
};
