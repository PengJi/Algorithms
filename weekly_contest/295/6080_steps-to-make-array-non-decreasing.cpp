class Solution {
public:
    int totalSteps(vector<int> &nums) {
        int ans = 0;
        stack<pair<int, int>> st;
        for (int num : nums) {
            int maxT = 0;
            while (!st.empty() && st.top().first <= num) {
                maxT = max(maxT, st.top().second);
                st.pop();
            }
            if (!st.empty()) ++maxT;
            ans = max(ans, maxT);
            st.emplace(num, maxT);
        }
        return ans;
    }
};
