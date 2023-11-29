class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        string forward = "";
        for(int i=0;i<s.size();i++) {
            if(isalpha(s[i]) or isdigit(s[i])) forward += s[i] ;
        }

        string backword ="";
        for(int i = s.size()-1; i>= 0; i--) {
            if(isalpha(s[i]) or isdigit(s[i])) backword += s[i];
        }
        cout << forward << ' '<< backword;
        return forward == backword;
    }
};