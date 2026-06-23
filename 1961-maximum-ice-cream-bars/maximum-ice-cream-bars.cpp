class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        int n=costs.size();                 

        int lar=0;
        for(auto v:costs){
            lar=max(lar,v);
        }

        vector<int> count(lar+1,0);
        vector<int> output(n);

        // 0 1 2 3 4 

        // 0 1 3 4 4  

        // 0 1 2 3 4 
        // 1 1 2 3 4              

        for(auto v:costs){
            count[v]++;
        }

        for(int i=0;i<=lar;i++){
            count[i]+= i>0 ? count[i-1] : 0; 
        }

        for(int i=n-1;i>=0;i--){
            output[count[costs[i]]-1]=costs[i];
            count[costs[i]]--; 
        }

        int i=0;

        int cnt=0; 

        while(i<n){
            // cout<<output[i]<<endl;        
            if(output[i]<=coins){
                coins-=output[i];
                cnt++; 
                i++;
            }
            else{
                break;
            }
        }

        return cnt;  
    }
};