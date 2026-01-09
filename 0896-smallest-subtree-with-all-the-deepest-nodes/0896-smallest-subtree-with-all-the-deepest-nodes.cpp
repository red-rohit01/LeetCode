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
public:
    TreeNode* res;
    int deepest=0;
    int dfs(TreeNode* root, int level)
    {
        if(root==nullptr) return level;

        int leftLevel=dfs(root->left, level+1);
        int rightLevel=dfs(root->right, level+1);

        int currLevel=max(leftLevel, rightLevel);
        deepest=max(deepest, currLevel);

        if(leftLevel==deepest && rightLevel==deepest) res=root;

        return currLevel;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root,0);
        return res;
    }
};