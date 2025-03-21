class Solution {
public:
    // It's simply based on Topological sorting to see which all recipes can be build and then move in the forward direction.
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        set<string>avail(supplies.begin(),supplies.end());
        int n=recipes.size();
        unordered_map<string,vector<string>>graph;

        unordered_map<string,int> indegree;
        for(auto &x:recipes) indegree[x]=0;

        for(int i=0;i<n;++i)
        {
            for(int j=0;j<ingredients[i].size();++j)
            {
                if(avail.find(ingredients[i][j])==avail.end())
                {
                    graph[ingredients[i][j]].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }

        queue<string>q;
        for(auto &x:indegree)
        {
            if(x.second==0) q.push(x.first);
        }

        vector<string>ans;

        while(!q.empty())
        {
            string temp=q.front();
            q.pop();
            ans.push_back(temp);

            for(auto &x:graph[temp])
            {
                if(--indegree[x]==0) q.push(x);
            }
        }
        return ans;
    }
};