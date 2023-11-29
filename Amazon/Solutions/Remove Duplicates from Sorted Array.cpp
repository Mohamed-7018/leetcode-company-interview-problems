class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    if (nums.size()==0) {
      return 0;
    }
    int xx = 0;
    for (int i = 0; i < nums.size(); i++) {
      int num = nums[i];
      if (num != nums[xx]) {
        xx++;
        nums[xx] = num;
      }
    }
    return xx + 1;
    }
        
    
};