class Compare {
public:
    bool operator()(const pair<int,int>& a,const pair<int,int>& b) {
        return b.second > a.second; 
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<=1) return nums;
        unordered_map<int,int> mp;
        for(int i: nums)
            mp[i]++;
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        for(auto i: mp) {
            pq.push(i);
        }
        vector<int> ans;
        while(k-- && !pq.empty()) {
            auto p = pq.top();
            pq.pop();
            ans.push_back(p.first);
        }
        return ans;
    }
};
