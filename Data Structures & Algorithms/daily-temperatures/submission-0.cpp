class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stk;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for(int i= n-1; i>=0; i--) {
            if(!stk.empty()) {
                while(!stk.empty()) {
                    auto curr = stk.top();
                    if(curr.second > temperatures[i]) {
                        ans[i] = curr.first - i;
                        break;
                    } else {
                        stk.pop();
                    }
                }
            }
            stk.push({i, temperatures[i]});
        }
        return ans;
    }
};
