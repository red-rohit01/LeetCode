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
    TreeNode* helper(int preS, int postS, int preE, vector<int>&pre, vector<int>&post)
    {
        if(preS>preE) return nullptr;
        
        TreeNode* root=new TreeNode(pre[preS]);
        if(preS==preE) return root;
        
        int j=postS;
        while(post[j]!=pre[preS+1]) j++;
        
        int len=j-postS+1;
        root->left=helper(preS+1,postS,preS+len,pre,post);
        root->right=helper(preS+len+1,j+1,preE,pre,post);
        
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        return helper(0,0,n-1,preorder,postorder);
    }
    
};