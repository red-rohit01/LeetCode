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
    // The core idea of this algorithm:
    // 1.Each depth of the tree only select one node.
    // 2. View depth is current size of result list.
    void helper(TreeNode* root, int curr_depth, vector<int>&ans)
    {
        if(root==nullptr) return;

        if(curr_depth==ans.size()) ans.push_back(root->val);

        helper(root->right,curr_depth+1,ans);
        helper(root->left,curr_depth+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==nullptr) return ans;
     
        helper(root,0,ans);
        return ans;
    }
};