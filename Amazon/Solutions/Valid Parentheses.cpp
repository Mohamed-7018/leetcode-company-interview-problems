class Solution {
public:
    bool isValid(string s) {
        
        vector<char> x;
        x.push_back('0');
      for(int i=0;i<s.size();i++) {
          if ( s[i] ==')' && x[x.size()-1]=='(' || s[i] ==']' && x[x.size()-1]=='[' || s[i] =='}' && x[x.size()-1]=='{' ) x.pop_back();
          else x.push_back(s[i]);
      }
    
      return x.size() == 1;
    }
};