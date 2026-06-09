class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), l=0, r=0, ans = 0;
        unordered_map<char, bool> mp;
        int curr = 0;
        while(l<=r && r<n) {
            if(mp.find(s[r]) == mp.end() || mp[s[r]] == false) {
                mp[s[r]] = true;
                r++;
                curr++;
                ans = max(ans, curr);
            }
            else {
                while(mp[s[r]] == true) {
                    mp[s[l]] = false;
                    l++;
                    curr--;
                }
            }
        }
        return ans;
    }
};
