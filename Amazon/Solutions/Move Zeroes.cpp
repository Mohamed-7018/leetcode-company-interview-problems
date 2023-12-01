class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> ans;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0)cnt++;
            else ans.push_back(nums[i]);
        }
        for(int i=0;i<cnt;i++) ans.push_back(0);
        nums.clear();
        for(int i=0;i<ans.size();i++) nums.push_back(ans[i]);
        
    }
};