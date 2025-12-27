class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n=nums.size();
        int ans=0; 
        for(int i=0;i<n;i++){
            set<int> s;                
            s.insert(nums[i]);
            int cnt=0; 

            for(int j=i+1;j<n;j++){

                if (s.find(nums[j]) != s.end()) {     
                    ans += cnt;
                    continue;
                } 

                s.insert(nums[j]);

                auto it1=s.find(nums[j]);    
                auto it0=it1;
                auto it2=it1;

                if(it1!=s.begin()){
                    it0=prev(it1);
                    if(*it1 - *it0 > 1){
                        cnt++;
                    }
                } 

                if(it1!=s.end()){
                    it2=next(it1);
                    if(*it2 - *it1 > 1){
                        cnt++;
                    }
                }
                

                if(it0!=it1 && it2!=it1 && (*it2-*it0)>1){  
                    cnt--; 
                }

                
                

                cout<<cnt<<endl; 

                ans+=cnt;


            }


        }

        return ans; 
    }
};