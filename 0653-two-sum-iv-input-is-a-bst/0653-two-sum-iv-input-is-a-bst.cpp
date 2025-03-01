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

class BSTIterator{
    public:
    stack<TreeNode*>st;
    bool is_increasing;
    BSTIterator(TreeNode* root,bool flag)
    {
        is_increasing=flag;
        push_all(root);
    }

    bool has_next()
    {
        return (!st.empty());
    }

    int next_element()
    {
        auto temp=st.top();
        st.pop();
        if(is_increasing) push_all(temp->right);
        else push_all(temp->left);
        return temp->val;
    }

    void push_all(TreeNode* root)
    {
        if(root==nullptr) return ;
        st.push(root);

        if(is_increasing) push_all(root->left);
        else push_all(root->right);
    }

};
class Solution {
public:
    // There is one another way, set the first pointer at first element and end pointer at last element. Now, a similar Two pointer approach
    // If the sum is less, then find the successor of the left pointer and move there.
    // If the sum is more, then find the predecessor of the right pointer and move there.
    // Here, predecessor and successor would be O(H). so, Total TC: O(N*H) and SC:O(1)


    // The solution we are implementing here is to use BSIterator and move 'left' and 'right' pointer using next and before pointer
    // TC: O(N) and SC: O(H)*2 
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root,true);
        BSTIterator r(root,false);

        int left=l.next_element();
        int right=r.next_element();
        while(left<right)
        {
            int curr=left+right;
            if(curr==k) return true;
            else if(curr<k) left=l.next_element();
            else right=r.next_element();
        }
        return false;
    }
};