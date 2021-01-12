/**
 * 1717. 删除子字符串的最大得分
 * https://leetcode-cn.com/problems/maximum-score-from-removing-substrings/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/maximum-score-from-removing-substrings/solution/yi-ci-bian-li-tan-xin-by-kobe24o-2723/
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        s.push_back('-'); // 方便代码处理
        int a = 0, b = 0;
        for(int i = 0; i < s.length(); ++i) 
        {
            if(s[i] != 'a' && s[i] != 'b') {   // 其他字符截断了
                if(a && b)//剩余的可以用较小的
                    ans += min(x,y)*min(a, b);
                a = b = 0;
            }
            else
            {
                if(s[i] == 'a') 
                    a++;
                else if(s[i] == 'b') 
                    b++;
                if(a && s[i]=='b' && x >= y)  // ab 优先
                    ans += x, a--, b--;
                else if(s[i]=='a' && b && x < y)  // ba优先
                    ans += y, a--,b--;
            }
        }
        return ans;
    }
};
