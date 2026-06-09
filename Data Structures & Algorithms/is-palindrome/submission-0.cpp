class Solution {
public:
    bool isValidChar(char c) {
        return (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9');
    }
    bool isPalindrome(string s) {
        int l=0, r=s.size()-1;
        while(l<r) {
            while(l<r && !isValidChar(s[l])) l++;
            while(r>l && !isValidChar(s[r])) r--;
            if(tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};
