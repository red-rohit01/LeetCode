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
    int ans=0;
    vector<int> helper(TreeNode* root)
    {
        vector<int>curr(2);
        if(root==nullptr) return curr;

        vector<int>temp1=helper(root->left);
        vector<int>temp2=helper(root->right);

        int total_elem=temp1[0]+temp2[0]+1;
        int total=temp1[1]+temp2[1];
        total+=root->val;

        int currAvg=total/total_elem;
        if(currAvg==root->val) ans++;

        curr[0]=total_elem;
        curr[1]=total;
        return curr;
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return ans;
    }
};