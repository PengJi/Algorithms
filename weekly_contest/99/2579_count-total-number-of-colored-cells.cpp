typedef long long LL;
class Solution {
public:
    long long coloredCells(int n) {
        return 1 + 2 * (LL)n * (n - 1);
    }
};
