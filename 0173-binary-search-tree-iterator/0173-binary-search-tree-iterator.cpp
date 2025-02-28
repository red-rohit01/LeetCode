class BSTIterator {
public:
    // Nice explanation by Pratyush Kumar at with dry run: https://leetcode.com/problems/binary-search-tree-iterator/solutions/1430547/c-simple-solution-using-stack-o-h-time-complexity-with-diagrammatic-explanation/
    
    // With this approach, we can merge Two BST efficiently
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        partialInorder(root);
    }
    
    void partialInorder(TreeNode* root){
        while(root != NULL)
        {
            s.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* top = s.top();
        s.pop();
        partialInorder(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};