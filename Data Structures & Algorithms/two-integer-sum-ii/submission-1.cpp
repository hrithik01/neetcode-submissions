class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0, r = numbers.size()-1;
        vector<int> ans;
        while(l<r) {
            int temp = numbers[l] + numbers[r];
            if(temp > target) r--;
            else if (temp < target) l++;
            else {
                ans.push_back(l+1);
                ans.push_back(r+1);
                return ans;
            }
        }
        return ans;
    }
};
