class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        queue<int> q;
        for(int i=1;i<=9;++i) q.push(i);

        while(!q.empty()) 
        {
            int f=q.front();
            q.pop();
            if(f<=high && f>=low) ans.push_back(f);

            if(f>high) break;

            int num=f%10;
            if(num<9) 
            {
                q.push(f * 10 + (num + 1));
            }
        }
        return ans;
    }
};