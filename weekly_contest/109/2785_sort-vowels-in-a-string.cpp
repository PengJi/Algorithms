/**
 * 2785. 将字符串中的元音字母排序
 * https://leetcode.cn/problems/sort-vowels-in-a-string/description/
*/
class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char, int> mp;
        mp['A'] = 0; mp['E'] = 1;
        mp['I'] = 2; mp['O'] = 3;
        mp['U'] = 4; mp['a'] = 5;
        mp['e'] = 6; mp['i'] = 7;
        mp['o'] = 8; mp['u'] = 9;
        const string v = "AEIOUaeiou";

        vector<int> cnt(10, 0);
        for (char c : s)
            if (mp.find(c) != mp.end())
                ++cnt[mp[c]];

        for (int i = 0, j = 0; i < s.size(); i++) {
            if (mp.find(s[i]) == mp.end())
                continue;

            while (cnt[j] == 0)
                j++;

            --cnt[j];
            s[i] = v[j];
        }

        return s;
    }
};
