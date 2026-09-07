class UndergroundSystem {
    unordered_map<string,unordered_map<string,int>> from_to_sum; 
    unordered_map<string,unordered_map<string,int>> from_to_cnt; 
    unordered_map<int,pair<string,int>> entry;            
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        entry[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int entry_time=entry[id].second;
        int exit_time=t;

        string src_station=entry[id].first;
        string dest_station=stationName;

        from_to_sum[src_station][dest_station]+=(exit_time-entry_time);
        from_to_cnt[src_station][dest_station]+=1;

        entry.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double)from_to_sum[startStation][endStation]/(double)from_to_cnt[startStation][endStation];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */