/**
 * 164. 最大间距
 * https://leetcode-cn.com/problems/maximum-gap/
 */

class Solution {
public:
    struct bucket {
        int Min = INT_MAX, Max = INT_MIN;
        bool used = false;
        bucket() {}
    };
    //  桶排序
    // https://www.acwing.com/solution/content/4337/
    int maximumGap(vector<int>& nums) {
        int n = nums.size(), Max = INT_MIN, Min = INT_MAX;
        if (n < 2) return 0;
        for (int i = 0; i < n; i++) {
            Max = max(Max, nums[i]);
            Min = min(Min, nums[i]);
        }
        int bucketSize = max(1, (Max - Min) / (n - 1));
        int bucketNum = (Max - Min) / bucketSize + 1;
        vector<bucket> buckets(bucketNum);
        for (int i = 0; i < n; i++) {
            int idx = (nums[i] - Min) / bucketSize;
            buckets[idx].used = true;
            buckets[idx].Min = min(buckets[idx].Min, nums[i]);
            buckets[idx].Max = max(buckets[idx].Max, nums[i]);
        }
        long long preBucketMax = Min, res = 0;
        for (int i = 0; i < bucketNum; i++) {
            if (!buckets[i].used)
                continue;
            res = max(res, buckets[i].Min - preBucketMax);
            preBucketMax = buckets[i].Max;
        }
        return res;
    }
};
