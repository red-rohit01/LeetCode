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
    vector<TreeNode*>rk;
    TreeNode* sortedarrayToBST(int st,int en)
    {
        if(st>en) return nullptr;

        int mid=(st+en)/2;
        TreeNode* root=rk[mid];
        root->left=sortedarrayToBST(st,mid-1);
        root->right=sortedarrayToBST(mid+1,en);
        return root;
    }
    void inorder(TreeNode* root)
    {
        if(root==nullptr) return;
        inorder(root->left);
        rk.push_back(root);
        inorder(root->right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        int len=rk.size();
        return sortedarrayToBST(0,len-1);
    }
};