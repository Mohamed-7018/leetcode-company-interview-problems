#define ll long long 
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        ll ans = 0;
        ll n = 0;
        for(int i=0;i<accounts.size();i++) {
            ans = 0;
            for(int j=0;j<accounts[i].size();j++) {
                ans += accounts[i][j];
            }
            n= max(n,ans);
        }
        return n;
    }
};