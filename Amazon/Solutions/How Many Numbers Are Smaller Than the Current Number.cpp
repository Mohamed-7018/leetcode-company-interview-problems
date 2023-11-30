#define show(C)           \
    for (auto J : C)      \
        cout << J << " "; \
    cout << endl;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> c,ans;
        map<int,int> m;
        for(int i=0;i<nums.size();i++) {
            c.push_back(nums[i]);
        }
        sort(c.begin(),c.end());
        show(c);
        for(int i=0;i<c.size();i++) {
            
            if(i!=0 && c[i]!=c[i-1])m[c[i]] = i;
           // cout << "-->" <<c[i]<< "-->"<< m[c[i]]<<endl;
        }

        for(int i=0;i<nums.size();i++){
            ans.push_back(m[nums[i]]);
        }

       return ans; 
       
    }
};