class Solution {
public:
    string minWindow(string s, string t) {
        int ns = s.size(), nt = t.size();
        if(nt == 0 || nt > ns) return "";
        unordered_map<char,int> goal, window;
        for(char c:t) {
            goal[c]++;
        }
        int req = goal.size(), curr = 0;
        int l= 0, ansl=0, anslen = ns+1;
        for(int i=0; i<ns; i++) {
            char c = s[i];
            window[c]++;
            if(goal.count(c) && window[c] == goal[c]) {
                curr++;
            }
            while(curr == req && l<=i) {
                if(i - l + 1 < anslen) {
                    anslen = i - l + 1;
                    ansl = l;
                }
                char cl = s[l];
                window[cl]--;
                if(goal.count(cl) && window[cl] < goal[cl]) {
                    curr--;
                }
                l++;
            }
        }
        return anslen == ns+1 ? "" : s.substr(ansl, anslen);
    }
};
