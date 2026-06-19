class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size(), l=0, r=n-1, mid, ans=INT_MAX;
        if(nums[l] <= nums[r]) return nums[l];
        if(nums[r]<nums[r-1] && nums[r]<nums[l]) return nums[r];
        while(l < r) {
            mid = l + (r-l)/2;
            if(nums[mid]<nums[mid+1] && nums[mid]<nums[mid-1]) return nums[mid];
            else if(nums[l] < nums[mid]) l = mid;
            else r = mid;
        }
        return ans;
    }
};
