#include <array>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp;
        map<array<int, 26>, vector<string>> mp;
        for(auto istr: strs) {
            array<int, 26> v{};
            for(char j: istr) {
                v[j - 'a']++;
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
