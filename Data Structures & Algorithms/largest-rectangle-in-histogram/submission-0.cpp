class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0;
        stack<pair<int,int>> stk;
        for(int i=0; i<n; i++) {
            int pushi = i;
            while(!stk.empty() && stk.top().second >= heights[i] ) {
                pushi = stk.top().first;
                ans = max(ans, stk.top().second * (i - pushi));
                stk.pop();
            }
            stk.push({ pushi, heights[i] });
        }
        while(!stk.empty()) {
            auto p = stk.top();
            ans = max(ans, p.second * (n - p.first));
            stk.pop();
        }
        return ans;
    }
};
