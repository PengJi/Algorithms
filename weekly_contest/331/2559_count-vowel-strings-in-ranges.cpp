class Solution {
public:
    // 前缀和
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        const int n = words.size();
        vector<int> p(n + 1);

        p[0] = 0;
        for (int i = 1; i <= n; i++)
            p[i] = p[i - 1] + 
                (isVowel(words[i - 1][0]) && isVowel(words[i - 1].back()));

        vector<int> ans;
        for (const auto &q : queries)
            ans.push_back(p[q[1] + 1] - p[q[0]]);

        return ans;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
