class Solution {
public:
    unordered_map<string,vector<char>> f;
    unordered_set<string> bad;

    bool nextlayer(string bottom, vector<string>& allowed, int i, string next){
        if(bottom.size() == 1){
            return true;
        }

        if(i == 0 && bad.count(bottom)){
            return false;
        }

        int n = bottom.size();

        if(i == n-1){
            bool ok = nextlayer(next, allowed, 0, "");
            if(!ok) bad.insert(bottom);
            return ok;
        }

        string str;
        str.push_back(bottom[i]);
        str.push_back(bottom[i+1]);

        if(f.find(str) == f.end()){
            return false;
        }

        for(auto c : f[str]){
            if(nextlayer(bottom, allowed, i+1, next + c)){  
                return true;
            }
        }

        if(i == 0) bad.insert(bottom); 
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {

        for(string str : allowed){
            string key;
            key.push_back(str[0]);
            key.push_back(str[1]);
            f[key].push_back(str[2]);
        }

        return nextlayer(bottom, allowed, 0, "");
    }
}; 