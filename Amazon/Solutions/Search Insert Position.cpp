class Solution {
private:
    int binarySearch(vector<int>& nums, int target){
        int l= 0; int r= nums.size()-1;
        int result = -1;
        while(l<=r) {
            int mid = (l+r)/2;
            if (nums[mid] >= target)  {
               result = mid; 
               r = mid-1;
            }
            else l = mid+1;
        }
        return r;
    }    
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target)+1;
    }
};