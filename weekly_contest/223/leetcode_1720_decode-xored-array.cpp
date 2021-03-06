/**
 * 5649. 解码异或后的数组
 * https://leetcode-cn.com/problems/decode-xored-array/
 */

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        
        for(int i = 0; i < encoded.size(); i++) {
            ans.push_back(encoded[i] ^ ans[i]);
        }
        
        return ans;
    }
};
