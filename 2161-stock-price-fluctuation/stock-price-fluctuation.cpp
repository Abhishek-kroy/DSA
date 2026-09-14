class StockPrice {
    unordered_map<int,int> ttop;
    int t;
    int price;
    priority_queue<pair<int,int>> mp;

    priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
    > minp;

public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        ttop[timestamp]=price;
        if(timestamp>=t){
            this->price=price;
            t=timestamp;
        }

        mp.push({price,timestamp});
        minp.push({price,timestamp});                
    }
    
    int current() {
        return price;
    }
    
    int maximum() {
        while(!mp.empty()){
            auto [p,t]=mp.top();
            // cout<<"price "<<p<<" t "<<t<<endl;        
            if(p==ttop[t]){
                // cout<<"returning "<<endl;        
                return p;
            }
            else{
                mp.pop();
            }
        }

        return -1;
    }
    
    int minimum() {
        while(!minp.empty()){
            auto [p,t]=minp.top();
            // cout<<"price "<<p<<" t "<<t<<endl;

            if(p==ttop[t]){
                // cout<<"returning "<<endl;
                return p;         
            }
            else{
                minp.pop();        
            }
        }

        return -1;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */