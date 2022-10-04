class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = 0;
        // 统计 num2 中1的个数
        while(num2) {
            cnt += num2 & 1;
            num2 >>= 1;
        }

        int res = 0;
        // 将高位的1抹去
        for(int i = 29; i >= 0 && cnt > 0; i--) {
            if(num1 >> i & 1) {
                res -= 1 << i;
                cnt--;
            }
        }

        // 如果 cnt 个1还没有被用完，则加到低位
        for(int i = 0; i < 30 && cnt > 0; i++) {
            if(!(num1 >> i & 1)) {
                res += 1 << i;
                cnt--;
            }
        }

        return (num1 + res) ^ num1;
    }
};
