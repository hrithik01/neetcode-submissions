class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++) {
            int key = target - nums[i];
            if(mp.find(key) != mp.end()) {
                ans.push_back(mp[key]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};
