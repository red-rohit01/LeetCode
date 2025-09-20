class Router {
public:
    // To track duplicates instead of storing it in map, we could also use something like a key here
    /*
      long long encode(int source, int destination, int timestamp) {
        return ((long long)source << 40) | ((long long)destination << 20) | timestamp;
    }
    */
    map<vector<int>, int> mpp; // to track duplicates
    queue<vector<int>> queue; // to store packets in FIFO order
    unordered_map<int, vector<int>> timestamps; // for timestamps tracking
    unordered_map<int, int> st; // To keep count of the already deleted corresponding to a destination 
    int maxSize = 0; // maxSize allowed

    Router(int memoryLimit) { 
        maxSize = memoryLimit; 
    }

    bool addPacket(int source, int destination, int timestamp) {
        vector<int> packet = {source, destination, timestamp};
        // checking for duplicate
        if (mpp.count(packet)) return false;
        if (queue.size() == maxSize) { // remove the first element if queue is full
            vector<int> res = queue.front();
            mpp.erase(res);
            int temp = res[1];
            st[temp]++;  
            queue.pop();
        }
        queue.push(packet);
        mpp[packet]++;
        timestamps[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if(queue.empty()) return {};
        vector<int> res = queue.front();
        queue.pop();
        mpp.erase(res);
        int temp = res[1];
        st[temp]++;
        return res;
    }

    int getCount(int destination, int startTime, int endTime) {
        if(timestamps.find(destination) == timestamps.end()) return 0;
        auto &p = timestamps[destination];
        int already_deleted=st[destination];
        auto right=lower_bound(p.begin() + already_deleted, p.end(), startTime);
        auto left=upper_bound(p.begin() + already_deleted, p.end(), endTime);
        return int(left - right);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */