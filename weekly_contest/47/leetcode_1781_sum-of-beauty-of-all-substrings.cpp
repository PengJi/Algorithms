/**
 * 5682. 所有子字符串美丽值之和
 * https://leetcode-cn.com/problems/sum-of-beauty-of-all-substrings/
 */

class Solution {
public:
    int beautySum(string s) {
        vector<int> vec(26, 0);
        int len = s.size();
        int cur_min, cur_max;
        int ans = 0;

        for(int i = 0; i < len; i++) {
            memset(&vec[0], 0, sizeof(vec[0])*26);

            for(int j = i; j < len; j++) {
                vec[s[j] - 'a']++;
                cur_min = INT_MAX;
                cur_max = 0;

                for(int item: vec) {
                    if(item != 0) {
                        cur_min = min(cur_min, item);
                        cur_max = max(cur_max, item);
                    }
                }

                ans += cur_max - cur_min;
            }
        }

        return ans;
    }
};
