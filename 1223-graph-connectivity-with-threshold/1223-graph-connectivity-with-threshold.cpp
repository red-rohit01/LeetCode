class Solution {
// The idea here is to use union-find data structure because all we care about is whether there exists an edge between a and b. If union-find finds that both a and b belong to the same component, then there is an edge between them.
// Now for union-find to do this, we will first set up the graph. The key idea to understand is that any integer node ‘a’ will be connected to all the multiples of ‘a’ provided that ‘a’ is greater than the threshold. For each number from 1 to n, we will connect it to its multiples using Union-Find with Rank and Path Compressions.

// For finding the multiples of each number in between [1,N], the time taken is O(NlogN)

// as N/1 + N/2 + N/3 + N/4 + N/5 + …..N/N = NlogN.

// Time Complexity : O(Q + NlogN).
// Space Complexity : O(Q + N).

// ∑r=1/r≈∫1/x dx=logn

class DSU{
    vector<int>parent;
    vector<int>sz;

    public:
    DSU(int n)
    {
        parent.resize(n+1,1);
        sz.resize(n+1,1);

        for(int i=1;i<=n;++i) parent[i]=i;
    }

    int find_upar(int u)
    {
        if(parent[u]==u) return u;

        return parent[u]=find_upar(parent[parent[u]]);
    }

    void merge(int u,int v)
    {
        int pu=find_upar(u);
        int pv=find_upar(v);

        if(pu==pv) return;

        if(sz[pu]>sz[pv])
        {
            parent[pv]=pu;
            sz[pu]+=sz[pv];
        }
        else 
        {
            parent[pu]=pv;
            sz[pv]+=sz[pu];
        }
    }
};
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        int m=queries.size();
        vector<bool>ans(m);
        if(threshold==0)
        {
            for(int i=0;i<m;++i) ans[i]=true;
            return ans;
        }

        DSU d(n);
        for(int i=threshold+1;i<=n;++i)
        {
            for(int j=2;(j*i)<=n;++j)
            {
                int pi=d.find_upar(i);
                int pj=d.find_upar(j*i);

                if(pi!=pj) d.merge(pi,pj);
            }
        }

        for(int i=0;i<m;++i)
        {
            int u=queries[i][0];
            int v=queries[i][1];
            if(u<=threshold || v<=threshold) ans[i]=0;
            else
            {
                int pu=d.find_upar(u);
                int pv=d.find_upar(v);

                if(pu==pv) ans[i]=1;
                else ans[i]=0;
            }
        }
        return ans;
    }
};

