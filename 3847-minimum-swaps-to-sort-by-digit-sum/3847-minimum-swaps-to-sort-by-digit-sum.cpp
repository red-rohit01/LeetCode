class Solution {
public:
    int digitSum(int n)
    {
        int sum=0;
        while(n!=0)
        {
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }

    void helper(vector<int>&nums,vector<pair<int,int>>&temp)
    {
        for(int i=0;i<nums.size();++i)
        {
            int sum=digitSum(nums[i]);
            temp.push_back({sum,nums[i]});
        }
    }
    int minSwaps(vector<int>& nums) {
        vector<pair<int,int>>temp;     // stores{digitSum, nums[i]}
        helper(nums,temp);

        sort(temp.begin(),temp.end(),[](auto &a, auto &b){
            if(a.first!=b.first) return a.first<b.first;

            return a.second<b.second;
        });

        int n=nums.size();
        vector<int>numsPosition(n);   // Inserted 'num' values in the sorted order of their digit sum
        for(int i=0;i<n;++i) numsPosition[i]=temp[i].second;

        unordered_map<int,int>idxOfnumsfinal;
        for(int i=0;i<n;++i) idxOfnumsfinal[numsPosition[i]]=i;

        unordered_map<int,int>finalToOrigidx;
        for(int i=0;i<n;++i) finalToOrigidx[i]=idxOfnumsfinal[nums[i]];

        vector<bool>visited(n);
        int cnt=0;
        for (int i=0;i<n;++i)
        {
            if(visited[i] || finalToOrigidx[i]==i) continue;
            int cycle_size=0;
            int j=i;
            while(!visited[j])
            {
                visited[j]=true;
                j=finalToOrigidx[j];
                cycle_size++;
            }
            if(cycle_size>1) cnt+=(cycle_size-1);       // cycle of size 'k' requires k-1 swaps
        }
        return cnt;
    }
};