class MedianFinder {
public:
    priority_queue<int> maxheap; // for smaller elements
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder() {
    }
    
    void addNum(int num) {
        this->maxheap.push(num);
        if(!this->minheap.empty()){
            if(this->minheap.top() < this->maxheap.top()){
                maxheap.push(minheap.top());
                minheap.pop();
            }
        }

        if(this->maxheap.size() - this->minheap.size() > 1){
            while(this->maxheap.size() - this->minheap.size() > 1){
                this->minheap.push(this->maxheap.top());
                this->maxheap.pop();
            }
        }
    }
    
    double findMedian() {
        if(this->maxheap.size() == this->minheap.size()){
            return (minheap.top() + maxheap.top())/2.0;
        }
        else{
            return double(maxheap.top());
        }
    }
};
