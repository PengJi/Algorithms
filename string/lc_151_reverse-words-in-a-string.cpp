/**
 * 151. 翻转字符串里的单词
 * https://leetcode-cn.com/problems/reverse-words-in-a-string/
 */

class Solution {
public:
    // 反转，反转整个字符串，反转单个单词
    // https://leetcode-cn.com/problems/reverse-words-in-a-string/solution/fan-zhuan-zi-fu-chuan-li-de-dan-ci-by-leetcode-sol/
    // O(n)/O(n)
    string reverseWords(string s) {
        // 反转整个字符串
        reverse(s.begin(), s.end());

        int n = s.size();
        int idx = 0;
        for (int start = 0; start < n; ++start) {
            if (s[start] != ' ') {
                // 填一个空白字符然后将idx移动到下一个单词的开头位置
                if (s != 0) s[idx++] = ' ';

                // 循环遍历至单词的末尾
                int end = start;
                while (end < n && s[end] != ' ') s[idx++] = s[end++];

                // 反转整个单词
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                // 更新start，去找下一个单词
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int idx = 0, len = s.size();
        int start, end;
        while (idx < len) {
            if (s[idx] == ' ') {
                idx++;
                continue;
            }
            start = end = idx;
            while (end < len && s[end] != ' ') end++;
            reverse(s.begin() + start, s.begin() + end);
            idx = end;
        }

        // 处理空格
        idx = 0;  // 空格字符索引
        for (int i = 0; i < len; i++) {
            if (s[i] != ' ') {
                int j = i;
                while (j < len && s[j] != ' ') s[idx++] = s[j++];
                s[idx++] = ' ';  // 每个单词后留一个空格
                i = j;
            }
        }

        // 删除多余字符
        s.erase(s.begin() + idx - 1, s.end());

        return s;
    }
};
