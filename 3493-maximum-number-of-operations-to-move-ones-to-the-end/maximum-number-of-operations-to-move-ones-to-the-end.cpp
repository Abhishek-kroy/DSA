class Solution {
public:
    int maxOperations(string s) {
        vector<int> cnt;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                int count=0;
                while(i<n && s[i]=='1'){
                    count++;
                    i++;
                }   
                if(i<=n-1) 
                    cnt.push_back(count);
            }
        }

        int ans=0;
        int prev=0;
        for(auto c:cnt){
            ans=ans+(c+prev);
            prev=c+prev;
        }

        return ans; 
    }
};