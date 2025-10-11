class MedianFinder {
public:
    priority_queue<int> maxHeap;    // This will store all the lower value elements
    priority_queue<int, vector<int>, greater<int>> minHeap;     // This will store all the higher value elements so that top will contain the lowest one
    
    MedianFinder() {
    }
    void addNum(int num) {
        minHeap.push(num);
        maxHeap.push(minHeap.top());
        minHeap.pop();
        if (maxHeap.size() > minHeap.size()) 
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    double findMedian() {
        if (minHeap.size() > maxHeap.size()) return minHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */