class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int cap;
    KthLargest(int k, vector<int>& nums) {
        this->cap = k;
        for(int i: nums){
            q.push(i);
        }
        while(q.size() >  k){
            q.pop();
        }
    }
    
    int add(int val) {
        if(q.size()>=cap){
            if(val >= q.top()){
                q.pop();
                q.push(val);
            }
        }
        else{q.push(val);}
        return q.top();
    }
};
