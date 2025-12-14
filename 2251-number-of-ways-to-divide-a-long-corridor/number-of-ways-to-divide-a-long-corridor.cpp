class Solution {
public:
    int MOD = 1e9+7; 

    int getans(int i,string& corridor){
        int n=corridor.size();
        if(i>=n)    return 1;

        int seat=0;
        while(i<n && seat<2){ 
            if(corridor[i]=='S'){
                seat++;
            }
            i++;
        } 

        if(seat!=2) return 0; 

        // int cnt=getans(i,corridor);  
        int way=1;
        while(i<n && corridor[i]=='P'){
            way++; 
            i++;
        }

        if(i>=n)    return 1; 

        int cnt=(1LL*way*getans(i,corridor)%MOD);               

        return cnt; 


    }

    int numberOfWays(string corridor) {
        int cnt=0;
        for(auto c:corridor){
            if(c=='S'){
                cnt++;
            }
        }

        if(cnt%2)   return 0;
        return getans(0,corridor);
    }
};