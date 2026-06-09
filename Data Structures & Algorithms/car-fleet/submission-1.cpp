class Solution {
public:
    static bool sortcustom(const pair<int,int>& a, const pair<int,int>& b) {
        return a.first > b.first;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> curr;
        int n = position.size();
        int ans = 0;
        double currtime = 0, maxtime = 0;
        for(int i=0; i<n; i++) {
            curr.push_back({position[i], speed[i]});
        }
        sort(curr.begin(), curr.end(), sortcustom);
        for(int i=0; i<curr.size(); i++) {
            currtime = double(target-curr[i].first)/curr[i].second;
            if(currtime > maxtime) {
                ans++;
                maxtime = currtime;
            }
        }
        return ans;
    }
};
/*
(8,2) (6,3)
  1.    1.33
*/
