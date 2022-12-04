/**
 * 6254. 划分技能点相等的团队
 * https://leetcode.cn/problems/divide-players-into-teams-of-equal-skill/description/
*/

typedef long long ll;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());

        int len = skill.size();
        int sum = skill[0] + skill[len-1];

        ll res = 0;
        for(int i = 0, j = len-1; i<j; i++, j--) {
            if(skill[i] + skill[j] != sum) return -1;
            res += skill[i] * skill[j];
        }

        return res;
    }
};
