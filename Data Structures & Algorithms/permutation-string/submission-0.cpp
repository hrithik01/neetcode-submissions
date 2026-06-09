class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;
        array<int, 26> goal = {0};
        array<int, 26> window = {0};
        for(char c: s1) {
            goal[c - 'a']++;
        }
        for(int i=0; i<n2; i++) {
            window[s2[i] - 'a']++;
            if(i >= n1) {
                window[s2[i-n1] - 'a']--;
            }
            if(window == goal) return true;
        }
        return false;
    }
};
