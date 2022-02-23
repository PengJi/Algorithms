template <class T> class FenwickTree {
  int limit;
  vector<T> arr;

  int lowbit(int x) { return x & (-x); }

public:
  FenwickTree(int limit) {
    this->limit = limit;
    arr = vector<T>(limit + 1);
  }

  void update(int idx, T delta) {
    for (; idx <= limit; idx += lowbit(idx))
      arr[idx] += delta;
  }

  T query(int idx) {
    T ans = 0;
    for (; idx > 0; idx -= lowbit(idx))
      ans += arr[idx];
    return ans;
  }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        FenwickTree<int> occur(n);
        unordered_map<int, int> pos;
        for (int i = 0; i < n; ++i)
            pos[nums2[i]] = i + 1;
        
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int idx = pos[nums1[i]];
            
            int left = occur.query(idx);
            int right = n - idx - (occur.query(n) - occur.query(idx));
            ans += 1LL * left * right;
            
            occur.update(idx, 1);
        }
        
        return ans;
    }
};
