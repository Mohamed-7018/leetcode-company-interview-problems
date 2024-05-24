class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i = 0 , j = 0;
        while(i < nums1.size() && j < nums2.size())
            if(nums1[i] <= nums2[j]) merged.push_back(nums1[i]) , i++;
            else merged.push_back(nums2[j]) , j++;
        
        while(i<nums1.size())
            merged.push_back(nums1[i]) , ++i;

        while (j < nums2.size())
            merged.push_back(nums2[j]) , ++j;
        
        if((nums1.size() + nums2.size()) % 2)
            return merged[(nums1.size() + nums2.size()) >> 1];
        else 
            return (merged[(nums1.size() + nums2.size()) / 2 - 1] + merged[(nums1.size() + nums2.size()) >>1] ) / 2.0 ;
    }
};