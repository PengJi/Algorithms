/**
 * 5489. 两球之间的磁力
 * https://leetcode-cn.com/problems/magnetic-force-between-two-balls/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/magnetic-force-between-two-balls/solution/er-fen-sou-su-45ms-by-geguanting/
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int high = (position[position.size()-1] - position[0]) / (m - 1);
        int low = 1;
        int ans = 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(position, mid, m)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

    bool check(vector<int> position, int dist, int m) {
        int count = 1;
        int j = 0;
        for(int i = 1; i < position.size(); i++) {
            if(position[i] - position[j] >= dist) {
                j = i;
                count++;
                if(count >= m) return true;
            }
        }

        return false;
    }
};
