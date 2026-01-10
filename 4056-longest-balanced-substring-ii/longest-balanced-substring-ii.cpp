class Solution {
public:
    int getcontinuous(string s,char c){
        int len=0;
        int maxi=0;
        for(auto v:s){
            if(v==c){      
                len++;
            }
            else{
                len=0;
            }
            maxi=max(maxi,len);
        }

        return maxi; 
    }

    int getcomb(string s,char a,char b){
        unordered_map<int,int> m;
        m[0]=-1;
        int cnt=0;

        int maxi=0;

        for(int i=0;i<s.size();i++){
            if(s[i]==a){
                cnt++;
            }
            else if(s[i]==b){
                cnt--;
            }
            else{
                m.clear();
                m[0]=i;
                cnt=0;         
            }  

            if(m.find(cnt)!=m.end()){
                maxi=max(maxi,i-m[cnt]);     
            }
            else{
                m[cnt]=i;
            }

        }

        return maxi ; 
    }

    int longestBalanced(string s) {
        // a-b=a-c    
        int w1=getcontinuous(s,'a');
        int w2=getcontinuous(s,'b');
        int w3=getcontinuous(s,'c');

        int w4=getcomb(s,'a','b');
        int w5=getcomb(s,'a','c');
        int w6=getcomb(s,'b','c');

        map<pair<int,int>,int> m;
        m[{0,0}]=-1;
        int cnta=0;
        int cntb=0;
        int cntc=0;

        int maxi=0;   

        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                cnta++;
            }
            if(s[i]=='b'){
                cntb++;
            }
            if(s[i]=='c'){
                cntc++;
            }

            if(m.find({cnta-cntb,cnta-cntc})!=m.end()){
                maxi=max(maxi,i-m[{cnta-cntb,cnta-cntc}]);
            }
            else{
                m[{cnta-cntb,cnta-cntc}]=i;          
            }
        }


        return max({w1,w2,w3,w4,w5,w6,maxi});      
    }
};