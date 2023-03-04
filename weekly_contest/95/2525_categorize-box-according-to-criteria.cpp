#define LL long long

class Solution {
public:
    // 模拟题
    string categorizeBox(int length, int width, int height, int mass) {
        bool bulky = false, heavy = mass >= 100;

        if (length >= 10000 || width >= 10000 || height >= 10000 ||
        (LL)(length) * width * height >= 1000000000)
            bulky = true;

        if (bulky && heavy)
            return "Both";

        if (!bulky && !heavy)
            return "Neither";

        if (bulky)
            return "Bulky";

        return "Heavy";
    }
};
