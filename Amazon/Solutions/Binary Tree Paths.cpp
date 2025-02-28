class Solution {
    vector<string> ANS;
    void solve(string ans, TreeNode* root ) {
        ans+=to_string(root->val);
        if(root->left == NULL && root->right == NULL) {   
            ANS.push_back(ans);
        }
        
        ans += "->";
        if(root->left) solve(ans,root->left);
        if(root->right) solve(ans,root->right);
    }
public:

    vector<string> binaryTreePaths(TreeNode* root) {
        string ans = "";
        solve(ans,root);

        return ANS;
    }
};