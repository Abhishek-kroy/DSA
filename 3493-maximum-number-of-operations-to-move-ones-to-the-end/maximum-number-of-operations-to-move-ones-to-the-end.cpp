class Solution {
public:
    int maxOperations(string s) {
        int ans=0;
        int prev=0;
        // vector<int> cnt;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                int count=0;
                while(i<n && s[i]=='1'){
                    count++;
                    i++;
                }   
                if(i<=n-1) {
                    int c=count;
                    ans=ans+(c+prev);
                    prev=c+prev;
                }
            }
        }

        // for(auto c:cnt){
            
        // }

        return ans; 
    }
};