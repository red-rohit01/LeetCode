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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=1;
        int val=INT_MIN;
        queue<TreeNode*>q;
        q.push(root);
        int level=1;
        while(!q.empty())
        {
            int sz=q.size();
            int temp=0;
            for(int i=0;i<sz;++i)
            {
                auto curr=q.front();
                q.pop();
                temp+=curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(temp>val)
            {
                ans=level;
                val=temp;
            }
            level++;
        }
        return ans;
    }
};