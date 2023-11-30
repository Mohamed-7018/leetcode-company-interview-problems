#define show(C)           \
    for (auto J : C)      \
        cout << J << " "; \
    cout << endl;



class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans,c;
         int n = arr.size();
        
         int mx = 0;
         for(int i = n-1; i>0;i--) {
             mx = max(mx,arr[i]);
             arr[i] = mx;
         }
        show ( arr);
        for(int i=1;i<n;i++){
            ans.push_back(arr[i]);
        }
        
         ans.push_back(-1);
        
        
        
        return ans;
        
    }
};