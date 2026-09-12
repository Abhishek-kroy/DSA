class Solution {
public:
    static vector<int> v;
    unordered_map<int,unordered_map<int,int>> dp;
    int getans(int n,int streak){
        if(n==0){
            return 0;
        }

        if(dp.find(n)!=dp.end() && dp[n].find(streak)!=dp[n].end()){
            return dp[n][streak];
        }

        int w1=INT_MAX;
        if(n-streak>=0){
            w1=1+getans(n-streak,streak+1);
        }

        int w2=INT_MAX;
        w2=2+getans(n-1,2);        

        return dp[n][streak]=min(w1,w2);
    }
    void built(){
       v[0]=-1;             

        for(int i=1;i<1e5;i++){
            int day=i*(i+1)/2;

            if(day>1e5){
                break;
            }

            v[day]=i;

            // cout<<"for day "<<day<<" takes "<<i<<endl; 
        }

        for(int day=2;day<=1e5;day++){
            if(v[day]!=-1){
                continue;        
            }

            int ans=INT_MAX;
            for(int k=1;k<=day;k++){
                int pre=k*(k+1)/2;

                if(pre>day){
                    break;
                }

                int days=k+1+v[day-pre];        
                ans=min(ans,days);
            }

            v[day]=ans;
        }  
    }
    int minDays(int n) {
        // return getans(n-1,2)+1;

        if(v[1]==-1){
            built();
        }

        // for(int i=0;i<=1e5;i++){
        //     cout<<"for day "<<i<<" takes "<<v[i]<<endl;        
        // }        

        return v[n];        
    }
};

vector<int> Solution::v(1e5+1,-1);