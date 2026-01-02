class Solution {
public:
    bool can(string k,int num,int mid){
        string s=k; 
        int i=0;
        int n=s.size();

        while(i<n){
            char c=s[i];
            int j=i;
            while(i<n && j<n && s[j]==c){   
                j++;
            }

            int len=(j-i)/(mid+1);    
            if(num<len) return false;     

            num-=len;      

            i=j;     
        }

        return true;
    }
    int minLength(string s, int numOps) {

        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<s.size();i++){
            if(i%2==0){
                if(s[i]!='0') cnt1++;
                if(s[i]!='1')   cnt2++;
            }
            else{
                if(s[i]!='1')   cnt1++;
                if(s[i]!='0')   cnt2++;      
            }
        }

        if(cnt1<=numOps || cnt2<=numOps)    return 1; 


        int l=2;
        int r=s.size(); 

        // string t=s;
        // reverse(t.begin(),t.end());  

        while(l<=r){
            int mid=(l+r)/2;

            if(can(s,numOps,mid)){     
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return l;  
    }
};