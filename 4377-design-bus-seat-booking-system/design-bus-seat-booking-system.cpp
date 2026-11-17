class BusBooking {
public:
    vector<vector<int>> isbooked;
    int bookingt;
    int bookeds;

    BusBooking(int n) {
        isbooked.assign(n+1,vector<int>(4,0));    
        bookingt=0;        
        bookeds=0;    
    }

    pair<int,int> getsea(const string& seat){
        int ind=seat[0]-'A';

        int num=0;
        for(int i=1;i<(int)seat.size();i++){
            num=num*10+(seat[i]-'0');
        }

        return {num,ind};
    }
    
    void toggle(string seat) {
        auto [row,ind]=getsea(seat);

        if(!isbooked[row][ind]){
            bookeds++;
            if(ind==0 || ind==3){
                if(ind==0){
                    if(isbooked[row][1]){
                        bookingt+=2;
                        isbooked[row][ind]+=2;
                    }
                }
                else{
                    if(isbooked[row][2]){
                        bookingt+=2;    
                        isbooked[row][ind]+=2;
                    }
                }
            }
            bookingt++;
            isbooked[row][ind]++;
        }
        else{
            bookeds--; 
            bookingt-=isbooked[row][ind];
            isbooked[row][ind]=0;         
        }
    }
    
    int getTotalTime() {
        return bookingt;        
    }
    
    int getMinTime() {
        return bookeds;    
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */