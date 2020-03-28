# 位运算

# 位运算符
|    含义   | 运算符 | 示例 |
| ---------- | --- | --- | 
| 左移 | << | 0011 => 0110 |
| 右移 | >> | 0110 => 0011 | 
| 按位或 | | | 0011 1011 => 1011 | 
| 按位与 | & | 0011 & 1011 =>  0011 | 
| 按位取反 | ~ | 0011 => 1100 | 
| 按位异或（相同为零不同为一）| ^ | 0011 ^ 1011 => 1000 |

# 位运算
1. 将 x 最右边的 n 位清零：x& (~0 << n)
2. 获取 x 的第 n 位值（0 或者 1）： (x >> n) & 1
3. 获取 x 的第 n 位的幂值：x& (1 << n)
4. 仅将第 n 位置为 1：x | (1 << n)
5. 仅将第 n 位置为 0：x & (~ (1 << n))
6. 将 x 最高位至第 n 位（含）清零：x& ((1 << n) -1)
7. 将第 n 位至第 0 位（含）清零：x& (~ ((1 << (n + 1)) -1))

# 位运算示例
1. 判断奇偶：  
x % 2 == 1 —> (x & 1) == 1
x % 2 == 0 —> (x & 1) == 0

2. x >> 1 —> x / 2. 
即： x = x / 2; —> x = x >> 1;
mid = (left + right) / 2; —> mid = (left + right) >> 1;

3. X = X & (X-1) 清零最低位的 1

4. X & -X => 得到最低位的 1

5. X & ~X => 0

# 题目
[191. 位1的个数](https://leetcode-cn.com/problems/number-of-1-bits/)  
[231. 2的幂](https://leetcode-cn.com/problems/power-of-two/)  
[190. 颠倒二进制位](https://leetcode-cn.com/problems/reverse-bits/)  
[51. N皇后](https://leetcode-cn.com/problems/n-queens/description/)  
[52. N皇后 II](https://leetcode-cn.com/problems/n-queens-ii/description/)


