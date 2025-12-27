class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        long long ans=0;

        vector<long long> even;  
        vector<long long> eventarget;    
        vector<long long> odd;
        vector<long long> oddtarget;

        for(auto val:nums){
            if(!(val%2))   even.push_back(val);
            else odd.push_back(val);
        }

        for(auto val:target){
            if(!(val%2))   eventarget.push_back(val);  
            else oddtarget.push_back(val);
        }

        sort(even.begin(),even.end()); 
        sort(eventarget.begin(),eventarget.end());
        sort(odd.begin(),odd.end());
        sort(oddtarget.begin(),oddtarget.end());

        long long moves=0;

        for(int i=0;i<even.size();i++){
            int stepsreq=abs(even[i]-eventarget[i])/2;
            ans+=stepsreq;
            // if(moves>=stepsreq){
            //     moves-=stepsreq;
            //     stepsreq=0;
            // }
            // else{
            //     stepsreq-=moves;
            //     moves=0;
            // }

            // if(stepsreq){
            //     ans+=stepsreq;
            //     moves+=stepsreq;
            // }
        } 

        for(int i=0;i<odd.size();i++){
            long long stepsreq=abs(odd[i]-oddtarget[i])/2;    
            ans+=stepsreq;
            // if(moves>=stepsreq){
            //     moves-=stepsreq;
            //     stepsreq=0;
            // }
            // else{
            //     stepsreq-=moves;
            //     moves=0;
            // }

            // if(stepsreq){
            //     ans+=stepsreq;
            //     moves+=stepsreq; 
            // }
        }

        return ans/2;  



    }
};     