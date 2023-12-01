class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> mp,mp1;
        for(auto i:magazine) mp[i]++;
        for(auto i:ransomNote) mp1[i]++;
        bool flag = true;
        for(auto i:mp1){
            if(mp[i.first]<mp1[i.first]) flag=false;
        }
        return flag;
    }
};