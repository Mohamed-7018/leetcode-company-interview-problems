class Solution {
public:
    int firstUniqChar(string s) {
        map<char, vector<int> > m;

        for(int i=0;i<s.size();i++) {
            m[s[i]].push_back(i);
        }

        map < int, char>  mm;vector<int> vv;
        for(const auto& elem : m) {
         if(elem.second.size() == 1) {
             mm [elem.second[0]] = elem.first;
             vv.push_back(elem.second[0]);
            }
        }

        sort(vv.begin(), vv.end());

        if (vv.size()>0) return vv[0];
     
        return -1;  
    }
};