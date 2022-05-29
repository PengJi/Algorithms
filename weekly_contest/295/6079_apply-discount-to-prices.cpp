class Solution {
public:
    // https://leetcode.cn/problems/apply-discount-to-prices/
    string discountPrices(string sentence, int discount) {
        string res;
        istringstream iss(sentence);
        string t;
        while(iss >> t) {
            bool is_price = (t[0] == '$');
            if(is_price) {
                for(int i = 1; i < t.size(); i++) {
                    if(t[i] == '$' || t[i] < '0' || t[i] > '9') {
                        is_price = false;
                        break;
                    }
                }
            }

            if(is_price && t.size() > 1) {
                string p = t.substr(1);
                double price = stod(p);
                price *= (100 - discount) * 0.01;

                ostringstream oss;
                oss << fixed << setprecision(2) << price;

                res += '$' + oss.str() + ' ';
            } else {
                res += t + ' ';
            }
        }

        res.pop_back();
        return res;
    }
};
