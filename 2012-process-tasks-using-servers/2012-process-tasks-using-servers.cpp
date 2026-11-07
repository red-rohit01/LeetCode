class Solution {
public:
    // Free heap: Stores (weight, index) and gives the server with the lowest weight. If weights are equal, it gives the lowest index.
    // Busy heap: Stores (freeTime, weight, index) and keeps the server that becomes free earliest at the top.

    // Move all servers whose freeTime <= j from the busy heap to the free heap.
    // If a free server is available: Pick the top server from the free heap. Assign the task to it.
    // Push it into the busy heap with freeTime = j + tasks[j].
    
    // If no server is free:
    // Pick the server at the top of the busy heap. Assign the task to it.
    // Update its free time to freeTime + tasks[j]
    
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using pii = pair<int, int>;
        using arr3 = array<long long, 3>;
        priority_queue<pii, vector<pii>, greater<pii>> free;
        priority_queue<arr3, vector<arr3>, greater<arr3>> busy;
        for(int i=0;i<servers.size();++i) free.push({servers[i], i});
        
        int m=tasks.size();
        vector<int> ans(m);
        for(int j=0;j<m;++j) 
        {
            while(!busy.empty() && busy.top()[0]<=j) 
            {
                auto [_, w, i] = busy.top();
                busy.pop();
                free.push({(int)w, (int)i});
            }
            if(!free.empty()) 
            {
                auto [w, i]=free.top();
                free.pop();
                ans[j] = i;
                busy.push({(long long)j + tasks[j], w, i});
            } 
            else 
            {
                auto [ft, w, i] = busy.top();
                busy.pop();
                ans[j] = (int)i;
                busy.push({ft + tasks[j], w, i});
            }
        }
        return ans;
    }
};