/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Better LC would have handled these things with an array instead of using a string
    void serialize_helper(TreeNode* root, string &ans)
    {
        if(root==nullptr)
        {
            ans+="*";    // using '*' to denote nullptr
            return;
        }
        
        ans+=to_string(root->val);
        ans+="#";                    // Using '#' to separate each of the values in case of string
        serialize_helper(root->left,ans);
        serialize_helper(root->right,ans);
    }
    // Encodes a tree to a single string
    string serialize(TreeNode *root) {
        // Your code here
        string ans="";
        serialize_helper(root, ans);
        return ans;
    }

    // Function to deserialize a list and construct the tree.
    TreeNode* deserialize_helper(string &arr, int &ind)
    {
        if(ind>=arr.size() || arr[ind]=='*')
        {
            ind++;
            return nullptr;
        }
        int val=0;
        bool flag=true;
        if(arr[ind]=='-')
        {
            flag=false;
            ind++;
        }
        while(ind<arr.size() && arr[ind]!='#')
        {
            val*=10;
            val+=(arr[ind]-'0');
            ind++;
        }
        if(flag==false) val*=-1;
        TreeNode* root=new TreeNode(val);
        ind++;
        root->left=deserialize_helper(arr,ind);
        root->right=deserialize_helper(arr,ind);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        // Your code here
        int ind=0;
        //cout<<data<<"\n";
        return deserialize_helper(data,ind);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));