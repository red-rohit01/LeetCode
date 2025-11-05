class Solution {
public:
    // Each add/remove → O(log n) due to SortedList
    // Each balance step keeps total reordering small
    // Overall TC: O(nlogn)
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        map<int,int>freq;
        multiset<pair<int,int>>top,rest;     // top stores the 'x' most frequent elements and 'rest' other elements
        vector<long long>ans;
        long long top_sum=0;

        auto balance=[&](){
            while((int)top.size()<x && !rest.empty())
            {
                auto it=rest.end();
                --it;
                top.insert(*it);
                top_sum+=1LL*it->first*it->second;
                rest.erase(it);
            }

            while((int)top.size()>x)
            {
                auto it=top.begin();
                top_sum-=1LL*it->first*it->second;
                rest.insert(*it);
                top.erase(it);
            }

            auto it1=rest.end();
            if(!rest.empty()) it1--;
            auto it2=top.begin();
            while(!rest.empty() && !top.empty() && *it1>*it2)
            {
                top_sum+=1LL*it1->first*it1->second-1LL*it2->first*it2->second;
                rest.insert(*it2);
                top.insert(*it1);
                rest.erase(it1);
                top.erase(it2);

                it1=rest.end();
                it1--;
                it2=top.begin();
            }
        };

        auto add=[&](int num)
        {
            pair<int,int>old={freq[num],num};
            if(top.find(old)!=top.end())
            {
                top.erase(top.find(old));
                top_sum-=1LL*old.first*old.second;
            }
            else if(rest.find(old)!=rest.end()) rest.erase(rest.find(old));

            freq[num]++;
            rest.insert({freq[num],num});
            balance();
        };

        auto remove=[&](int num)
        {
            pair<int,int>old={freq[num],num};
            if(top.find(old)!=top.end())
            {
                top.erase(top.find(old));
                top_sum-=1LL*old.first*old.second;
            }
            else rest.erase(rest.find(old));

            freq[num]--;
            if(freq[num]>0) rest.insert({freq[num],num});

            else freq.erase(num);
            
            balance();
        };

        for(int i=0;i<k;++i) add(nums[i]);

        ans.push_back(top_sum);

        for(int i=k;i<n;++i)
        {
            remove(nums[i-k]);
            add(nums[i]);
            ans.push_back(top_sum);
        }
        return ans;
    };
};