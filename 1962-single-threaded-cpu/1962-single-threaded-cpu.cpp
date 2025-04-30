class Solution {
    typedef pair<int, int> T; // processing time, index
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; //min heap of tasks,sorted first by processing time then by index.
        long long n=tasks.size(),time=0,i=0; // `time` is the current time, `i` is the read pointer
        for (int i=0;i<n;++i) tasks[i].push_back(i); // append the index to each task so that we can read it at the end
        sort(tasks.begin(), tasks.end()); // sort the input array so that we can take the tasks of small enqueueTime first

        vector<int> ans;
        while (i<n || pq.size()) { // stop the loop when we exhausted the input array and the tasks in the heap.
            if(pq.empty()) 
            {
                time=max(time, (long long)tasks[i][0]); // nothing in the heap? try updating the current time using the processing time of the next task in array
            }
            while(i<n && time>=tasks[i][0]) 
            {
                pq.emplace(tasks[i][1], tasks[i][2]);
                ++i;
            }
            auto[process, index]=pq.top();
            pq.pop();
            time+=process; 
            ans.push_back(index);
        }
        return ans;
    }
};
