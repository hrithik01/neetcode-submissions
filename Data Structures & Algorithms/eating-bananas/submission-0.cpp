class Solution {
public:
    int ceilDiv(int a, int b) {
        return (a+b-1)/b;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), l = 1, r=1, ans = INT_MAX, anscurr = INT_MAX, curr = 0;
        for(int i: piles)
            r = max(r, i);
        while(l <= r) {
            int mid = l + (r-l)/2;
            curr = 0;
            for(int i: piles) {
                curr += ceilDiv(i, mid);
            }
            if(curr <= h) {
                anscurr = mid;
                ans = min(ans, anscurr);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
