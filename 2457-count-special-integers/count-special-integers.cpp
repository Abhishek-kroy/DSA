class Solution {
public:
    int getlen(int n){
        int len=0;
        while(n){
            len++;
            n=n/10;
        }
        return len;
    }

    map<pair<int,bool>,int> dp;  

    int getans(string n,int ind,bool tight,int mask){
        if(ind==n.size()){
            return 1;
        }

        if(dp.find({mask,tight})!=dp.end()) return dp[{mask,tight}];

        int w=0;

        int lowlimit = mask==0 ? 1 : 0;
        int highlimit = tight ? n[ind]-'0' : 9;

        for(int i=lowlimit;i<=highlimit;i++){
            if(mask&(1<<(i+1))) continue;   

            bool ntight= tight && (i==n[ind]-'0')  ;            
            int nmask=mask|(1<<(i+1));
            w+=getans(n,ind+1,ntight,nmask) ;              
        }  

        return dp[{mask,tight}]=w;              
    }

    int countSpecialNumbers(int n) {
        int ans=0;
        int len=getlen(n);
        int power=9;
        int cnt=9;
        for(int l=1;l<len;l++){
            ans+=power;
            if(l!=1){
                cnt--;
            }          
            power=power*cnt;  
        }

        return ans+getans(to_string(n),0,true,0);
    }
};

// 9 + 9*9+ 9*9*8 + 9*9*8*7;