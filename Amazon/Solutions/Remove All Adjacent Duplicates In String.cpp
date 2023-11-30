class Solution {
private :
   string removedjacent(string s){
       string ANS ="";
       for(int i=1;i<s.size();i++) {
           if(s[i] == s[i-1]) {
               s[i] ='?';
               s[i-1] ='?';
           }
       }
       for(auto it : s) if(it != '?') ANS += it;
       return ANS;
   }    
public:
    string removeDuplicates(string s) {
        string res = "";
        for (char& c : s)
            if (res.size() && c == res.back())
                res.pop_back();
            else
                res.push_back(c);
        return res;
   
    }
};