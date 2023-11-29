#define show(C)           \
    for (auto J : C)      \
        cout << J << " "; \
    cout << endl;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(numRows >1) ans.push_back({1,1}); 
       
        int size  = 3;

        for(int x=2;x<numRows;x++) {
            vector <int> v;
            v.push_back(1);
            for(int i=1;i<x;i++) {
                cout << x-1 <<"-"<<i-1 << " ";
            v.push_back(ans[x-1][i-1]+ ans[x-1][i]);  
            }
            cout<<endl;

            v.push_back(1);
            ans.push_back(v);

        }
        return ans;
        
    }
};