class RandomizedCollection {
    vector<int> v;
    
    unordered_map<int, unordered_set<int>> valtoi;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool first = (valtoi.find(val) == valtoi.end());

        v.push_back(val);

        valtoi[val].insert(v.size() - 1);

        return first;
    }

    bool remove(int val) {
        if (valtoi.find(val) == valtoi.end())
            return false;

        // Any index containing val
        int ind = *valtoi[val].begin();

        // Last element
        int lastVal = v.back();
        int lastInd = v.size() - 1;

        // Remove the old index of val
        valtoi[val].erase(ind);

        // Move last element to ind
        if (ind != lastInd) {
            v[ind] = lastVal;

            valtoi[lastVal].erase(lastInd);
            valtoi[lastVal].insert(ind);
        }

        v.pop_back();

        // No more occurrences
        if (valtoi[val].empty())
            valtoi.erase(val);

        return true;
    }

    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */