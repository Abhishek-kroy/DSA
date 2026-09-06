class MyQueue {
    stack<int> sti;
    stack<int> sto;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        sti.push(x);
    }
    
    int pop() {
        if(sto.empty()){
            while(!sti.empty()){
                sto.push(sti.top());
                sti.pop();
            }
        }

        if(!sto.empty()){
            int value=sto.top();
            sto.pop();        
            return value;    
        }

        return -1;
    }
    
    int peek() {
         if(sto.empty()){
            while(!sti.empty()){
                sto.push(sti.top());
                sti.pop();
            }
        }

        if(!sto.empty()){
            int value=sto.top();        
            return value;    
        }

        return -1;
    }
    
    bool empty() {
        return sti.empty() && sto.empty();        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */