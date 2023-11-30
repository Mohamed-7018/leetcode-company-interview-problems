class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int N = 1;
        vector<int> missing;

        // first integet
        for(int i=1;i<arr[0];i++) {
            missing.push_back(i);
        } 
        
       int current  = arr[0]+1;
       int i= 1;
       while(i != arr.size()){
            if(missing.size()  >= k) break;


            if (current != arr[i]){
                missing.push_back(current);
                current++;
            }else{
                i++;
                current ++;
            }
        }
        for(auto it: missing) cout << it  << ' ';
        if(missing.size()< k) return arr[arr.size()-1] + (k-missing.size());
        return missing[k-1];
    }
};