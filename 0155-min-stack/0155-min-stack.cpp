class MinStack {
private:
    stack<pair<int, int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        //When ever we push we check the top element & add min to the pair
        if(st.empty()){
            st.push({val, val});
        } else {
            int top = st.top().second;
            st.push({val, min(top, val)});
        }
    }
    
    void pop() {
        //Simple Pop
        st.pop();
    }
    
    int top() {
        //Simple top
        return st.top().first;
    }
    
    int getMin() {
        //Get the Top.second
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */