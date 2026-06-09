class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), l = 0, r = 0, ans = 0, minL = prices[0];
        while(r<n-1) {
            r++;
            if(prices[r] < minL){
                minL = prices[r];
            }
            int curr = prices[r] - minL;
            ans = max(curr, ans);
        }
        return ans;
    }
};
/*
[7,1,5,3,6,4]
10 3 10 1 9 5
 0 1  2 3 4 5
*/