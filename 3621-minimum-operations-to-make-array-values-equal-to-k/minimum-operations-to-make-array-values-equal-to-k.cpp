class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int min_ele=100;
        unordered_set<int> s;
        int cnt=0;
        for(auto v:nums){
            if(s.find(v)==s.end()){
                cnt++;
            }
            s.insert(v);
            min_ele=min(min_ele,v);
        }

        if(min_ele<k){
            return -1;
        }
        if(min_ele==k){
            return cnt-1;
        }

        return cnt;
    }
};