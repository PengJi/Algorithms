class Solution {
public:
    int bestClosingTime(string customers) {
       const int n = customers.size();
       int r = 0;
       for(int c : customers) {
           if(c == 'Y') r++;
       }

       int min = r, ans = 0;
       int l = 0;

       for(int i = 0; i < n; i++) {
           if(customers[i] == 'N') l++;
           else r--;

           if(min > l + r){
               min = l + r;
               ans = i + 1;
           }
       }

       return ans;
    }
};
