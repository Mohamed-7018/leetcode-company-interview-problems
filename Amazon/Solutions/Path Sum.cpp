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
    int t  = 0; 
    bool solve(TreeNode* root, int sum ) {
        if(!root) return false;
        if(!root->left  and !root->right and sum + root->val != t)  return false;
        else if (!root->left  and !root->right and sum+root->val == t) return true;

        return solve (root->right , sum + root->val) or solve(root->left, sum + root->val);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        t = targetSum ;

        return solve(root, 0 );
    }
};