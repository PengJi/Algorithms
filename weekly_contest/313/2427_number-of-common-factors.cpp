class Solution {
public:
    int commonFactors(int a, int b) {
        int res = 0;
        for(int i = 1; i <= a; i++) {
            if(b % i == 0 && a % i ==0) res++;
        }

        return res;
    }
};
