class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long > res;
        long long cur = 0, cnt = 0;
        
        if(finalSum % 2 != 0) return res;

        while(true) {
            cur += 2;
            cnt += cur;
            if(cnt == finalSum) {
                res.push_back(cur);
                break;
            } else if(cnt < finalSum) {
                res.push_back(cur);
            } else {
                res.pop_back();
                break;
            }
        }
        
        if(cnt == finalSum) return res;

        cnt = 0;
        for(int i = 0; i < res.size(); i++) {
            cnt += res[i];
        }
        res.push_back(finalSum - cnt);
        
        return res;
    }
};
