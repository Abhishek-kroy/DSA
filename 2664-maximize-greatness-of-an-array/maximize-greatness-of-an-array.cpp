class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n=nums.size();

        vector<int> ans(n);

        multiset<int> s;
        for(auto v:nums){
            s.insert(v);
        }

        int cnt=0;

        for(int i=0;i<n;i++){
            auto it=s.upper_bound(nums[i]);

            if(it==s.end()){
                cout<<*s.begin()<<endl;    
                ans[i]=*s.begin();
                s.erase(s.begin());
            }
            else{
                cnt++;            
                cout<<*it<<endl;
                ans[i]=*it;
                s.erase(it);
            }
        }        

        return cnt;    
    }
};