/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ANS = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto node = q.front();
                q.pop();
                if (!node->left && !node->right)
                    return ANS;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ANS++;
        }
        return ANS;
    }
};


// *-------------------------------------------------  *//
// *----------------Anoter Solution------------------  *//
// *-------------------------------------------------  *//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    vector<vector<int>> adj;
    int ANS;

public:
    Solution() { ANS = 0; }
    int dfs(TreeNode* node, int depth = 0) {
        if (!node)
            return depth;
        if ( node->right == NULL)
            return dfs(node->left, depth + 1);
        if ( node->left == NULL)
            return dfs(node->right, depth + 1);  

        return min(dfs(node->left, depth + 1), dfs(node->right, depth + 1));      
    }
    int minDepth(TreeNode* root) { return dfs(root); }
};
