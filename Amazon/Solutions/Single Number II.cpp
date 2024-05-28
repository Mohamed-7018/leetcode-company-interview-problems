class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size(); i++ ){
            cout << nums[i] ;
            if(i+2<nums.size()) {
                if(nums[i] == nums[i+1] and nums[i] == nums[i+2]) i=i+2;
                else return nums[i];
            }
            else return nums[i];
        }
        return -1;
    }
};