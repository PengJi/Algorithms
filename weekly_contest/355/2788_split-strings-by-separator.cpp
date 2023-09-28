/**
 * 2788. 按分隔符拆分字符串
 * https://leetcode.cn/problems/split-strings-by-separator/description/
*/
class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;

        for (const string &w : words) {
            string cur;
            for (int i = 0; i <= w.size(); i++) {
                if (i == w.size() || w[i] == separator) {
                    if (!cur.empty())
                        ans.push_back(cur);

                    cur.clear();
                } else {
                    cur += w[i];
                }
            }
        }

        return ans;
    }
};
