class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children)
            return -1;

        if (money > children * 8)
            return children - 1;

        int x = (money - children) / 7;
        int r = (money - children) % 7;

        if (x == children - 1 && r == 3)
            return x - 1;

        return x;
    }
};
