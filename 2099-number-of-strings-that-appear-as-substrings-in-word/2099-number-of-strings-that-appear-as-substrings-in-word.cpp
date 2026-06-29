class Solution {
public:
    // Want to give it a trie
    class Trie {
public:
    class Node{
        public:
        bool ew;
        vector<Node*>children;
        Node()
        {
            children.resize(26);
            for(int i=0;i<26;++i) children[i]=nullptr;
            ew=false;
        }
    };

    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* temp=root;
        int len=word.size();
        for(int i=0;i<len;++i)
        {
            int ind=word[i]-'a';
            if(temp->children[ind]==nullptr) temp->children[ind]=new Node();
            
            temp=temp->children[ind];
        }
        temp->ew=true;
    }
    
    bool search(string word) {
        Node* temp=root;
        int len=word.size();
        for(int i=0;i<len;++i)
        {
            int ind=word[i]-'a';
            if(temp->children[ind]==nullptr)
            {
                return false;
            }
            temp=temp->children[ind];
        }
        return temp->ew;
    }
    
    bool startsWith(string prefix) {
        Node* temp=root;
        int len=prefix.size();
        for(int i=0;i<len;++i)
        {
            int ind=prefix[i]-'a';
            if(temp->children[ind]==nullptr)
            {
                return false;
            }
            temp=temp->children[ind];
        }
        return true;
    }
};

    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0;
        for (const string& s:patterns)
            if(word.find(s)!=string::npos) ans++;
        return ans;
    }
};