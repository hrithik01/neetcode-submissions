class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(!nums.size()) return 0;
        int ans = 1, res = 1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == nums[i-1])
                continue;
            if(nums[i] == (nums[i-1] + 1)) {
                ans++;
            } else {
                ans = 1;
            }
            res = max(ans, res);
        }
        return res;
    }
};
