class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), l=0, r=0, ans = 0, maxf = 0;
        int count[26] = {0};
        while(r<n) {
            int idx = s[r] - 'A';
            count[idx]++;
            maxf = max(maxf, count[idx]);
            while((r-l+1) - maxf > k) {
                count[s[l] - 'A']--;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};
/*
XYYX
l0 r0 cx1 cy0 maxf1 curr1 ans1
l0 r1 cx1 cy1 maxf1 curr2 ans2
l0 r2 cx1 cy2 maxf2 curr3 ans3
l0 r3 cx2 cy2 maxf2 curr4 ans4
*/
