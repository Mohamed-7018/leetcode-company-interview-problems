class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char> ss(s.size());
        for(int i= 0 ; i< s.size(); i++) ss[i] = s[i];
        s.clear();
        for(int i=ss.size()-1;i>=0;i--){
            cout <<  ss[i];
            s.push_back(ss[i]);
        }
    }
};