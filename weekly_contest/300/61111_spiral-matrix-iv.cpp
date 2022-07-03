/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* p) {
        vector<vector<int>> res(m, vector(n, -1));
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        int x = 0, y = 0, d = 1;
        for(int i = 0; i < m * n && p; i++) {
            res[x][y] = p->val;
            int a = x + dx[d], b = y + dy[d];
            if(a < 0 || a >= m || b < 0 || b >= n || res[a][b] != -1) {
                d = (d + 1) % 4;
                a = x + dx[d];
                b = y + dy[d];
            }
            x = a, y = b;
            p = p->next;
        }
        return res;
    }
};
