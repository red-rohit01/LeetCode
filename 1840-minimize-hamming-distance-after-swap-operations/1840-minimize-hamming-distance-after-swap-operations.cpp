#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]); // path compression

        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if(px!=py) parent[px] = py;
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        DSU dsu(n);
        for(auto &swap : allowedSwaps) dsu.unite(swap[0], swap[1]);
        
        // Group indices
        unordered_map<int, vector<int>> groups;
        for(int i=0;i<n;++i) 
        {
            int p=dsu.find(i);
            groups[p].push_back(i);
        }

        int distance=0;
        for(auto &it:groups) 
        {
            auto &indices=it.second;
            unordered_map<int,int>freq;

            // Count source values
            for(int idx:indices) freq[source[idx]]++;
            
            // Match with target
            for(int idx:indices) 
            {
                if (freq[target[idx]]>0) freq[target[idx]]--;
                else distance++;
            }
        }
        return distance;
    }
};