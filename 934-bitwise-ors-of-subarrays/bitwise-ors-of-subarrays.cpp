class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> s;
        int n=arr.size();
        unordered_set<int> cur;
        for(int i=n-1;i>=0;i--){
            int val=arr[i];
            unordered_set<int> tem;
            tem.insert(val);
            s.insert(val);                        
            for(auto v:cur){
                if(v|val!=val){
                    tem.insert(v|val);
                    s.insert(v|val);
                }
            }
            cur=tem;
        }
        return s.size();
    }
};