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
    TreeNode* helper(vector<int>&pre,int st,int en)
    {
        if(st>en) return nullptr;

        if(st==en)
        {
            TreeNode* temp=new TreeNode(pre[st]);
            return temp;
        }

        int root_val=pre[st];
        int limit=lower_bound(pre.begin()+st+1,pre.begin()+en+1,root_val)-pre.begin();   // Although It should not work since, the vector is not sorted
        // Better would be to have a linear traversal to get the first element greater than the root_val.
        TreeNode* root=new TreeNode(root_val);
        root->left=helper(pre,st+1,limit-1);
        root->right=helper(pre,limit,en);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        return helper(preorder,0,n-1);
    }
};