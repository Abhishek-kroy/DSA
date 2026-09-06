class RandomizedSet {
    vector<int> v;
    unordered_map<int,int> vtoi;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(vtoi.find(val)==vtoi.end()){
            v.push_back(val);
            vtoi[val]=v.size()-1;
            return true;
        }

        return false;
    }
    
    bool remove(int val) {
        if(vtoi.find(val)!=vtoi.end()){
            int ind=vtoi[val];
            vtoi.erase(val);
            int n=v.size();        
            if(ind!=n-1){
                swap(v[ind],v[n-1]);
                vtoi[v[ind]]=ind;
            }

            v.pop_back();

            return true;
        }

        return false;
    }
    
    int getRandom() {
        return v[rand()%(int)v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */