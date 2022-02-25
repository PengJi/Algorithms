class Solution {
public:
    bool sum_is_even(int n) {
        int sum = 0;
        while(n > 0) {
            sum += n % 10;
            n /= 10;
        }
        if(sum % 2 == 0) return true;
        else return false;
    }
    int countEven(int num) {
        int res = 0;
        int cur = 2;
        while(cur <= num) {
            if(sum_is_even(cur)) res++;
            cur++;
        }
        
        return res;
    }
};
