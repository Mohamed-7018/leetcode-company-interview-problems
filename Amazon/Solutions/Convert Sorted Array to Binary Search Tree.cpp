/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int> n;
    TreeNode* solve(int l, int h) {
        if(l<=h){
            int mid = (l+h) >> 1;
            TreeNode* root=new TreeNode(n[mid]);
            root->left = solve(l, mid-1);
            root->right = solve(mid+1 , h );
            return root; 
        }
        return nullptr;
    } 
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        for(auto &it : nums) n.push_back(it);

        return solve(0 , nums.size() - 1 );
    }
};