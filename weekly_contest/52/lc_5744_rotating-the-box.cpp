/**
 * 5744. 旋转盒子
 * https://leetcode-cn.com/problems/rotating-the-box/
 */

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> res(n, vector<char>(m));
        for(int i = 0; i < n; i++) {
            for(int j = m-1, k = 0; j >= 0; j--, k++) {
                res[i][k] = box[j][i];
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = n - 1, k = n; j >= 0; j--) {
                if(res[j][i] == '*') 
                    k = j;
                else if(res[j][i] == '#') {
                    res[j][i] = '.';
                    res[--k][i] = '#';
                }
            }
        }

        return res;
    }
};
