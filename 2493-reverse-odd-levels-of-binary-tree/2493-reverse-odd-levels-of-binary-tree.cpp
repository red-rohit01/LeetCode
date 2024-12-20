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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==nullptr) return root;

        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty())
        {
            int l=q.size();
            vector<TreeNode*> curr_Nodes;
            for(int i=0;i<l;++i)
            {
                TreeNode* curr=q.front();
                q.pop();
                curr_Nodes.push_back(curr);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(level%2==1)
            {
                int left=0,right=l-1;
                while(left<right)
                {
                    swap(curr_Nodes[left]->val,curr_Nodes[right]->val);
                    left++;
                    right--;
                }
            } 
            level++;
        }
        return root;
    }
};