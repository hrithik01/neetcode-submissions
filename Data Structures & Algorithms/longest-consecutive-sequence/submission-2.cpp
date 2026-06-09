class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for(int i: s) {
            if(s.find(i-1) == s.end()) {
                int curr = i, currlen = 1;
                while(s.find(curr+1) != s.end()) {
                    curr++;
                    currlen++;
                }
                ans = max(ans, currlen);
            }
        }
        return ans;
        // sort(nums.begin(), nums.end());
        // if(!nums.size()) return 0;
        // int ans = 1, res = 1;
        // for(int i=1; i<nums.size(); i++) {
        //     if(nums[i] == nums[i-1])
        //         continue;
        //     if(nums[i] == (nums[i-1] + 1)) {
        //         ans++;
        //     } else {
        //         ans = 1;
        //     }
        //     res = max(ans, res);
        // }
        // return res;
    }
};
