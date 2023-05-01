class Solution {
public:
    int passThePillow(int n, int time) {
        int x = time % (2 * n - 2);

        return x <= n - 1 ? x + 1 : 2 * n - x - 1;
    }
};
