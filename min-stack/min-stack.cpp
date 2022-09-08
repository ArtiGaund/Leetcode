class MinStack {
public:
   stack<int>st;
    stack<int>st1;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(st1.empty()){
            st1.push(val);
        }
        else{
            if(st1.top()>=val){
                st1.push(val);
            }
        }
    }
    
    void pop() {
        
        if(st.top()==st1.top())
        st1.pop();
        st.pop();
    }
    
    int top() {
        int y=st.top();
        return y;
    }
    
    int getMin() {
        if(st1.empty())return NULL;
       return st1.top();
        
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