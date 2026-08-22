class Solution {
public:
    int cntone(int val){
        int cnt=0;

        while(val>0){
            cnt+=(val&1);

            val>>=1;
        }

        return cnt;
    }
    int longestAwesome(string s) {
        unordered_map<int,int> freq;
        int n=s.size();

        int ans=0;
        int sum=0;
        freq[0]=-1;
        for(int i=0;i<n;i++){
            sum=sum^(1<<(s[i]-'0'));

            if(freq.find(sum)!=freq.end()){
                ans=max(ans,i-freq[sum]);
            }

            for(int j=0;j<10;j++){
                int t=sum^(1<<j);
                if(freq.find(t)!=freq.end()){    
                    ans=max(ans,i-freq[t]);
                }
            }

            if(freq.find(sum)==freq.end()){
                freq[sum]=i;    
            }
        }

        return ans;    
    }
};