class Solution {
public:
    // 模拟
    int maximumValue(vector<string>& strs) {
        int res = 0;
        
        for(const auto &str : strs) {
            int r = 0;
            for(char c: str) {
                if(!isdigit(c)) {
                    r = str.size();
                    break;
                }

                r = r * 10 + c - '0';
            }

            res = max(res, r);
        }

        return res;
    }
};
