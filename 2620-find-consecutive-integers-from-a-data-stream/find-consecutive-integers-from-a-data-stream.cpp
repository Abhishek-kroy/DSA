class DataStream {
    int value;
    int freq;
    int max_freq;
public:
    DataStream(int _value, int k) {
        value=_value;
        freq=0;
        max_freq=k;
    }
    
    bool consec(int num) {
        if(num!=value){
            freq=0;
            return false;
        }
        freq++;
        if(freq<max_freq){
            return false;
        }

        return true;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */