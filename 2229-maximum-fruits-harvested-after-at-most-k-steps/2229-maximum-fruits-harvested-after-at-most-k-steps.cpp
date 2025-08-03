class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=fruits.size();
        map<int,int>val;   // stores the number of fruits for each of the position. so that we can apply lower_bound effectively
        bool flag=false;
        int ans=0;
        for(int i=0;i<n;++i)
        {
            val[fruits[i][0]]=fruits[i][1];
            if(fruits[i][0]==startPos)
            {
                flag=true;
                ans+=fruits[i][1];
            }
        }
        auto it=val.lower_bound(startPos);

        auto itr1=it;
        int curr_sum=0;
        map<int,int>left;   // stores the cumulative amount of fruit starting from 'startPos' and moving to left side.
        while(itr1!=val.begin())
        {
            itr1--;
            curr_sum+=(itr1->second);
            int ind=itr1->first;
            left[startPos-ind]=curr_sum;
        }
        
        map<int,int>right; // stores the cumulative amount of fruit starting from 'startPos' and moving to right side.
        auto itr2=it;
        if(itr2->first == startPos) itr2++;
        curr_sum=0;
        while(itr2!=val.end())
        {
            curr_sum+=(itr2->second);
            int ind=itr2->first;
            right[ind-startPos]=curr_sum;
            itr2++;
        }
        // for(auto &x:left)
        // {
        //     cout<<x.first<<" "<<x.second<<"\n";
        // }
        //cout<<left.size()<<" "<<right.size()<<"\n";

        itr1=left.begin();
        while(left.size()>0 && itr1!=left.end())     // Moving to some of the left side and the reverse to move to the right side
        {
            int sum=0;
            if(flag) sum+=val[startPos];
            sum+=(itr1->second);
            int steps=(itr1->first);
            if(steps>k) break;
            ans=max(ans,sum);
            int rem=k-2*steps;
            if(rem<0 || right.size()==0)  
            {
                itr1++;
                continue;
            }
            auto l=right.lower_bound(rem);
            if(l==right.begin() && l->first > rem)   //If the first element on the right side itself is at greater distance than the rem
            {
                itr1++;
                continue;
            }

            if(l==right.end() || (l->first > rem)) l--;
            
            sum+=l->second;
            ans=max(ans,sum);
            itr1++;
        }
        itr2=right.begin();

        while(right.size()>0 && itr2!=right.end())
        {
            int sum=0;
            if(flag) sum+=val[startPos];
            sum+=(itr2->second);
            int steps=itr2->first;
            if(steps>k) break;

            ans=max(ans,sum);

            int rem=k-2*steps;
            if(rem<0 || left.size()==0)
            {
                itr2++;
                continue;
            }
            auto l=left.lower_bound(rem);
            if(l==left.begin() && l->first>rem) 
            {
                itr2++;
                continue;
            }
            if(l==left.end() || l->first>rem) l--;

            sum+=l->second;
            ans=max(ans,sum);
            itr2++;
        }
        return ans;
    }
};