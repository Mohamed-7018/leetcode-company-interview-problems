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
    int t = 0 ;
    vector<vector<int>> ANS;
    void rec(vector<int> &ans, TreeNode* root , int sum) {
        if(!root->left and !root->right and sum+root->val==t) ANS.push_back(ans);
        if(!root->left and !root->right and sum+root->val!=t) return;
        
        if(root->left) {
            ans.push_back(root->left->val);
            rec(ans,root->left, sum + root->val);
            ans.pop_back();
        }
        if(root->right) {
            ans.push_back(root->right->val);
            rec(ans,root->right, sum + root->val);
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        t = targetSum;

        vector<int> ans;
       if(!root)  return ANS;

       ans.push_back(root->val);
        rec(ans,root,0);

        return ANS;
    }
};