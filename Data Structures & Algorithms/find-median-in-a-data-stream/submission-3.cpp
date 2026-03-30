class MedianFinder {
public:

    priority_queue<int, vector<int>> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxheap.push(num);
        // cout << "maxheap : " << num << endl;
        if(maxheap.size() - minheap.size() > 1){
            minheap.push(maxheap.top());
            // cout << "minheap : " << minheap.top();
            maxheap.pop();
        }
        if(!minheap.empty() && minheap.top() < maxheap.top()){
            maxheap.push(minheap.top());
            // cout << "maxheap : " << maxheap.top() << endl;
            minheap.pop();
            minheap.push(maxheap.top());
            // cout << "minhea : " << minheap.top() << endl;
            maxheap.pop();
        }
    }
    
    double findMedian() {
        if(maxheap.size() > minheap.size()) return double(maxheap.top());
        return double((maxheap.top() + minheap.top())/2.0);
    }
};
