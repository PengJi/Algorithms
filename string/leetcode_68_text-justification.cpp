/**
 * 68. 文本左右对齐
 * https://leetcode-cn.com/problems/text-justification/
 */

class Solution {
public:
    // https://www.acwing.com/solution/content/152/
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for(int i = 0; i < words.size(); i++) {
            int j = i+1;  // 当前行可填充的最后一个单词的下标
            int len = words[i].size();
            // 当前行可填充的单词
            while(j < words.size() && len+1+words[j].size() <= maxWidth) {
                len += 1 + words[j++].size();
            }

            string line;
            if(j == words.size() || j == i+1) {  // 左对齐：1. 最后一行；2. 当前行只有一个单词
                line += words[i];
                for(int k = i+1; k < j; k++) line += ' ' + words[k];  // 当为最后一行时，右边补充空格
                while(line.size() < maxWidth) line += ' ';  // 补充空格
            } else {  // 左右对齐
                int cnt = j-i-1;  // 空隙数
                int left_space = maxWidth - len + cnt;  // 待补充的空格数
                line += words[i];
                int k = 0;  // 待补充的单词数
                // 比如：7 个空格，2 个空隙， 共 3 个单词
                // 空格数分别为：3、2、2
                while(k < left_space % cnt) {
                    line += string(left_space/cnt+1, ' ') + words[i+k+1];
                    k++;
                }
                while(k < cnt) {
                    line += string(left_space/cnt, ' ') + words[i+k+1];
                    k++;
                }
            }

            res.push_back(line);
            i = j - 1;
        }

        return res;
    }
};
