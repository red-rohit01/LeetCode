class Solution {
public:
    class Node{
    public:
    Node* children[2];
    Node()
    {
        for(auto &x:children)
        {
            x=nullptr;
        }
    }
};

class Trie{
  Node* root;
  public:
  Trie()
  {
      root=new Node();
  }
  
  void insert(int n)
  {
      Node* ptr=root;
      for(int i=31;i>=0;--i)
      {
          int bit=(n>>i)&1;
          if(ptr->children[bit]==nullptr) ptr->children[bit]=new Node();
          
          ptr=ptr->children[bit];
      }
  }
  
  int get_mx_xor(int n)
  {
      Node* ptr=root;
      int res=0;
      for(int i=31;i>=0;--i)
      {
          int bit=(n>>i)&1;
          
          if(ptr->children[!bit]!=nullptr) 
          {
              res=(res| (1<<i));
              ptr=ptr->children[!bit];
          }
          else ptr=ptr->children[bit];
      }
      
      return res;
  }
};

    int findMaximumXOR(vector<int>& nums) {
        // Trie* t=new Trie();
        // int n=arr.size();
        // int ans=0;
        // for(int i=0;i<n;++i)
        // {
        //     t->insert(nums[i]);
        // }
        
        // for(int i=0;i<n;++i)
        // {
        //     int curr=t->get_mx_xor(nums[i]);
        //     ans=max(ans,curr);
        // }
        // return ans;

        int ans=0;
        int mask=0;
        int n=nums.size();
        for(int i=31;i>=0;--i)
        {
            //The mask will grow like  100..000 , 110..000, 111..000,  then 1111...111
            //for each iteration, we only care about the left parts
            mask=mask | (1<<i);

            set<int>st;
            for(int j=0;j<n;++j)
            {
                // we only care about the left parts, for example, if i = 2, then we have
                // {1100, 1000, 0100, 0000} (only first 2 digits) from {1110, 1011, 0111, 0010}

                int left_part=mask&nums[j];
                st.insert(left_part);
            }
            int greedy_val=ans|(1<<i);

            for(auto &x:st)
            {
                //This is the most tricky part, coming from a fact that if a ^ b = c, then a ^ c = b;
                // now we have the 'c', which is greedyTry, and we have the 'a', which is leftPartOfNum
                // If we hope the formula a ^ b = c to be valid, then we need the b, 
                // and to get b, we need a ^ c, if a ^ c exisited in our set, then we're good to go
                int second_num=greedy_val^x;    
                if(st.find(second_num)!=st.end())
                {
                    ans=greedy_val;
                    break;
                }
            }
        }
        return ans;
    }
};