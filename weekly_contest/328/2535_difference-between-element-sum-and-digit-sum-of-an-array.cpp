class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int x = 0, y = 0;

        for (int a : nums) {
            x += a;
            while (a) {
                y += a % 10;
                a /= 10;
            }
        }

        return abs(x - y);
    }
};
