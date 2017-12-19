class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    int min = INT_MAX;
    MinStack() {
        
    }
    
    void push(int x) {
        if (x<=min){
        	st.push(min);//store last min
        	min = x;
        }
        st.push(x);
    }
    
    void pop() {
    	if (st.top()==min){
    		st.pop();
    		min = st.top();
    	}
    	st.pop();     
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
    	return min;
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 *