class Solution {
public:
    // 排序，去重
    int similarPairs(vector<string>& words) {
        for (auto& word: words) {
            sort(word.begin(), word.end());
            word.erase(unique(word.begin(), word.end()), word.end());
        }

        int res = 0;
        for (int i = 0; i < words.size(); i ++ ) {
            for (int j = 0; j < i; j ++ ) {
                if (words[i] == words[j])
                    res ++ ;
            }
        }

        return res;
    }
};
