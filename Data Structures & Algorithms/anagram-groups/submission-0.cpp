class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp;
        map<vector<int>, vector<string>> mp;
        for(int i=0; i<strs.size(); i++) {
            vector<int> v(26, 0);
            string istr = strs[i];
            for(int j=0; j<istr.size(); j++) {
                v[istr[j] - 'a']++;
            }
            if(mp.find(v) != mp.end()) {
                mp[v].push_back(istr);
            } else {
                vector<string> vstr = {istr};
                mp[v] = vstr;
            }
        }
        vector<vector<string>> ans;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            ans.push_back(it->second);
        }
        return ans;
    }
};
