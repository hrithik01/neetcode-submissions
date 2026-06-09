class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==0 || n==0 || k>n) return {};
        deque<int> dq;
        vector<int> ans;
        for(int i=0; i<n; i++) {
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k-1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
/*
[1,2,1,0,4,2,6] (nums) k = 3
 0 1 2 3 4 5 6 (i)
 dq
 i0= 0 ans{}
 i1= 1 ans{}
 i2= 12 ans{2}
 i3= 123 ans{2,2}
 i4= 45 ans{2,2,4,4}
i6= 
*/