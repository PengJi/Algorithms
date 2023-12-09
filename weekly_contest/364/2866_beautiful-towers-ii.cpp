/**
 * 2866. 美丽塔 II
 * https://leetcode.cn/problems/beautiful-towers-ii/description/
*/
#define LL long long

class Solution {
public:
    LL maximumSumOfHeights(vector<int>& maxHeights) {
        const int n = maxHeights.size();
        vector<LL> left(n);
        stack<int> st;

        st.push(-1);
        LL tot = 0;
        for (int i = 0; i < n; i++) {
            while (st.size() > 1 && maxHeights[i] < maxHeights[st.top()]) {
                int top = st.top();
                st.pop();
                tot -= (LL)(top - st.top()) * maxHeights[top];
            }

            tot += (LL)(i - st.top()) * maxHeights[i];
            st.push(i);
            left[i] = tot;
        }

        while (!st.empty())
            st.pop();

        st.push(n);
        tot = 0;
        LL ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() > 1 && maxHeights[i] < maxHeights[st.top()]) {
                int top = st.top();
                st.pop();
                tot -= (LL)(st.top() - top) * maxHeights[top];
            }

            tot += (LL)(st.top() - i) * maxHeights[i];
            st.push(i);
            ans = max(ans, left[i] + tot - maxHeights[i]);
        }

        return ans;
    }
};
