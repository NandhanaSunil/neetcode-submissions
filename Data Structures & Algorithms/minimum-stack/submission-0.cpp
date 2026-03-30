class MinStack {
public:
    vector <int> stv;
    MinStack() {
        
    }
    
    void push(int val) {
        stv.push_back(val);
    }
    
    void pop() {
        stv.pop_back();
    }
    
    int top() {
        return stv[stv.size()-1];

    }
    
    int getMin() {
        auto it = min_element(stv.begin(), stv.end());
        return *it;
    }
};
