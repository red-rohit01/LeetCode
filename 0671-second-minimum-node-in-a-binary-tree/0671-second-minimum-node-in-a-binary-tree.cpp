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
    vector<long long> helper(TreeNode* root)
    {
        vector<long long>curr(2);
        curr[0]=1e13;
        curr[1]=1e13;
        if(root==nullptr) return curr;

        auto lh=helper(root->left);
        auto rh=helper(root->right);

        set<long long>st(lh.begin(),lh.end());
        st.insert(rh[0]);
        st.insert(rh[1]);
        st.insert(1LL*root->val);

        auto itr=st.begin();
        long long val1=*(itr);
        itr++;
        long long val2=*(itr);
        return {val1,val2};
    }
    int findSecondMinimumValue(TreeNode* root) {
        auto temp=helper(root);
        if(temp[1]==1e13) return -1;
        return temp[1];
    }
};