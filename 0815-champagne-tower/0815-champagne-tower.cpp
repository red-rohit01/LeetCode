class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double>curr(101,(double)(poured));
        for(int r=1;r<=query_row;++r)
        {
            vector<double>next(101);
            for(int c=0;c<r;++c)
            {
                double rem=(curr[c]-1.0)/2.0;
                if(rem>0)
                {
                    next[c]+=rem;
                    next[c+1]+=rem;
                }
            }
            curr=next;
        }
        return min(1.0,curr[query_glass]);
    }
};