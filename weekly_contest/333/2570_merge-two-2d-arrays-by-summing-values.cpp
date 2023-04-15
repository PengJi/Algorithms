class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, 
        vector<vector<int>>& nums2
    ) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while (i < nums1.size() || j < nums2.size()) {
            if (j == nums2.size()) {
                ans.push_back(nums1[i]);
                i++;
            } else if (i == nums1.size()) {
                ans.push_back(nums2[j]);
                j++;
            } else {
                if (nums1[i][0] == nums2[j][0]) {
                    ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                    i++; j++;
                } else if (nums1[i][0] < nums2[j][0]) {
                    ans.push_back(nums1[i]);
                    i++;
                } else {
                    ans.push_back(nums2[j]);
                    j++;
                }
            }
        }

        return ans;
    }
};

作者：wzc1995
链接：https://www.acwing.com/solution/content/170782/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。