class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;
        int maxL = height[0];
        vector<int> left(n,0);
        left[0] = height[0];
        for(int i=1; i<n; i++) {
            maxL = max(height[i], maxL);
            left[i] = maxL;
        }
        int maxR = height[n-1], ans = 0;
        for(int i=n-2; i>=1; i--) {
            maxR = max(maxR, height[i]);
            ans += (min(left[i], maxR) - height[i]);
        }
        return ans;
    }
};
/*
[0,2,0,3,1,0,1,3,2,1]

0 2 2 3 3 3 3 3 3 3

3 3 3 3 3 3 3 3 2 1

*/