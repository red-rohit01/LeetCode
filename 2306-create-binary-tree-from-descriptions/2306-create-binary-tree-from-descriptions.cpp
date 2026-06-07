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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n=descriptions.size();
        map<int,TreeNode*>getNode;
        map<int,bool> is_child;  // We'll mark all the nodes who are child to any node and the node which is not child will be root 

        for(auto &x:descriptions)
        {
            if(getNode.count(x[0])==0)    // If this parentNode doesn't exist already then create it
            {
                TreeNode* curr=new TreeNode(x[0]);
                getNode[x[0]]=curr;
            }
            if(getNode.count(x[1])==0)   // If this childNode doesn't exist already then create it
            {
                TreeNode* curr=new TreeNode(x[1]);
                getNode[x[1]]=curr;
            }

            TreeNode* par=getNode[x[0]];
            if(x[2]==1) par->left=getNode[x[1]];
            else par->right=getNode[x[1]];

            is_child[x[1]]=true;
        }

        for(auto &x:descriptions)
        {
            if(is_child[x[0]]==false) return getNode[x[0]];
        }
        return nullptr;
    }
};