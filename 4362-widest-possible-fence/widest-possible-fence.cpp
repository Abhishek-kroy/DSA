class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        sort(planks.begin(),planks.end());

        unordered_map<int,int> f;
        unordered_map<int,int> t;

        for(auto v:planks){
            f[v]++;
            t[v]++;
        }

        // 1=> 2 
        // 2=> 2 
        // 3=> 1
        // 4=> 1
        // 5=> 2 
        // 7=> 1    


        int n=planks.size();
        for(auto p:f){
            int num1=p.first;
            int freq1=p.second;
            for(auto p2:f){
                int num2=p2.first;
                int freq2=p2.second;

                if(num1==num2){
                    t[num1+num2]+=freq1/2;
                }                         
                else if(num1<num2){
                    t[num1+num2]+=min(freq1,freq2);        
                }       
            }
        }    

        int ans=0;

        for(auto [num,freq]:t){
            ans=max(ans,freq);    
        }        

        return ans;    
    }
};