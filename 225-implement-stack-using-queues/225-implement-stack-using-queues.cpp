class MyStack {
public:
    
    queue <int> q1;
    queue <int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
         while(!q1.empty()){
            int temp = q1.front();
            q2.push(temp);
            q1.pop();
        }
        // while(!q2.empty()){
        //     int temp = q2.front();
        //     q1.push(temp);
        //     q2.pop();
        // }
        swap(q1, q2);
    }
    
    int pop() {
        if(q1.empty()) return -1;
        int front = q1.front();
        q1.pop();
        return front;
    }
    
    int top() {
        if(q1.empty()) return -1;
        int front = q1.front();
        return front;
    }
    
    bool empty() {
        return (q1.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */