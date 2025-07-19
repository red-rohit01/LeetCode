class Node{
    public:
    Node* child[26];
    int ew=0;
    Node()
    {
        ew=0;
        for(int i=0;i<26;++i) child[i]=nullptr;
    }
};

class Trie{
    public:
    Node* root;
    Trie()
    {
        root=new Node();
    }
    void insert(string &word)
    {
        Node* temp=root;
        for(auto &x:word)
        {
            if(x=='/') continue;
            int ind=x-'a';
            if(temp->child[ind]==nullptr) temp->child[ind]=new Node();

            if(temp->child[ind]->ew>0) return;

            temp=temp->child[ind];
        }
        temp->ew++;
    }
};

void helper(Node *root,vector<string>&ans,string &curr)
{
    if(root==nullptr) return;
    if(root->ew>0)
    {
        string temp=curr;
        temp.pop_back();
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<26;++i)
    {
        if(root->child[i]!=nullptr)
        {
            char c=(char)('a'+i);
            curr+=c;
            curr+="/";
            helper(root->child[i],ans,curr);
            curr.pop_back();
            curr.pop_back();
        }
    }
}

//This Trie based normal solution would not work. Reason being, we can't find the index of 'ca'

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n=folder.size();

        // Trie t;
        // for(int i=0;i<n;++i)
        // {
        //     t.insert(folder[i]);
        // }
        // vector<string>ans;
        // string curr="/";
        // Node* root=t.root;
        // helper(root,ans,curr);
        // return ans;

        sort(folder.begin(), folder.end());

        vector<string>result;
        result.push_back(folder[0]);

        for(int i=1;i<n;++i) 
        {
            string lastFolder=result.back();
            lastFolder+='/';

            // Check if the last folder is prefix of the current folder path. If not then add to result
            if (folder[i].compare(0, lastFolder.size(), lastFolder) != 0) result.push_back(folder[i]);
        }
        return result;
    }
};