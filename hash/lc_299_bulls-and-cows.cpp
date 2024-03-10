/**
 * 299. 猜数字游戏
 * https://leetcode-cn.com/problems/bulls-and-cows/
 */

class Solution {
public:
    // https://www.acwing.com/activity/content/code/content/456565/
    string getHint(string secret, string guess) {
        unordered_map<char, int> hash;
        for (auto c : secret)
            hash[c]++;
        int tot = 0;
        for (auto c : guess)
            if (hash[c]) {
                tot++;
                hash[c]--;
            }

        int bulls = 0;
        for (int i = 0; i < secret.size(); i++)
            if (secret[i] == guess[i])
                bulls++;

        return to_string(bulls) + "A" + to_string(tot - bulls) + "B";
    }
};
