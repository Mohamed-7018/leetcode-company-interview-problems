class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto &it : nums) {
            it = it*it;
        }

        sort(nums.begin(), nums.end());
        return nums;
    }
};