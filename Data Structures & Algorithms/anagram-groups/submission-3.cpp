#include <array>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<uint8_t,26>, vector<string>> mp;
        for (const auto &istr : strs) {
            array<uint8_t,26> v{};               
            for (char c : istr) ++v[c - 'a'];
            mp[v].push_back(istr);           
        }
        vector<vector<string>> ans;
        for (auto &p : mp) ans.push_back(p.second);
        return ans;
    }
};
