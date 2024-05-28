/**
 * 41. 缺失的第一个正数
 * https://leetcode-cn.com/problems/first-missing-positive/
 */
class Solution {
public:
    // 哈希表
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto it : nums) {
            s.insert(it);
        }

        int ans = 1;
        while(s.count(ans)) ans++;

        return ans;
    }
};

class Solution {
public:
    // 置换
    // 数组应当有 [1, 2, ..., N] 的形式，但其中有若干个位置上的数是错误的，
    // 每一个错误的位置就代表了一个缺失的正数。以题目中的示例二 [3, 4, -1, 1] 为例，
    // 恢复后的数组应当为 [1, -1, 3, 4]，我们就可以知道缺失的数为 222。
    // 我们可以对数组进行一次遍历，对于遍历到的数 x=nums[i]，如果 x∈[1,N]，
    // 我们就知道 x 应当出现在数组中的 x−1 的位置，因此交换 nums[i] 和 nums[x−1]，
    // 这样 x 就出现在了正确的位置。
    // 在完成交换后，新的 nums[i] 可能还在 [1,N] 的范围内，我们需要继续进行交换操作，直到 x∉[1,N]。
    // 如果 nums[i]恰好与 nums[x−1] 相等，那么就会无限交换下去。此时我们有 nums[i]=x=nums[x−1]，
    // 说明 x 已经出现在了正确的位置。因此我们可以跳出循环，开始遍历下一个数。
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 1;

        for(auto& it : nums) {
            if(it != INT_MIN) it--;
        }

        for(int i = 0; i < len; i++) {
            while(nums[i] >= 0 && nums[i] < len && nums[i] != i && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            }
        }

        for(int i = 0; i < len; i++) {
            if(nums[i] != i) return i+1;
        }

        return len+1;
    }
};
