class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0 )return false;
        else {
            int a = 0;
            std::string s = std::to_string(x);
             for(int i=0;i<s.size()/2; i++) {
             if(s[i] == s[s.size() - 1 - i]) a++;
            }
             if(a == (s.size() / 2))return true;
        }
	 return false;
    }
};