class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        
        int elemCounted = 1;
        int prevElem = nums[0];
        
        for (int index = 1; index < nums.size(); ++index) {
            if (nums[index] != prevElem) {
                elemCounted += 1;
                prevElem = nums[index];
            }
            
            if (elemCounted == 3) {
                return nums[index];
            }
        }
        
        return nums[0];
    }
};