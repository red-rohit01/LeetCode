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
    const int mod=1000000007;
    long long totalTreeSum=0,result=0;
    int helper(TreeNode* root)           
    {
        if(root==NULL) return 0;
        
        long long sum=helper(root->left)+helper(root->right)+root->val; 
        result=max(result,sum*(totalTreeSum-sum));    
        return sum;
    }
    int maxProduct(TreeNode* root) {
        totalTreeSum=helper(root);
        helper(root);
        return result%mod;
    }
};