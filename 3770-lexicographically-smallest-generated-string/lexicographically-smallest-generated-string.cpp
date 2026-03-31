class Solution {
public:
    string generateString(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        string ans="";
        for(int i=0;i<n+m-1;i++){
            ans+='a';
        }   

        vector<bool> fixed(n+m-1,false);

        for(int i=0;i<n;i++){    
            if(str1[i]=='T'){
                for(int j=0;j<m;j++){   
                    if(fixed[i+j] && ans[i+j]!=str2[j]){
                        return "";
                    }
                    else{
                        ans[i+j]=str2[j];   
                    }
                    fixed[i+j]=true;   
                }
            }
        }

        for(int i=0;i<n;i++){
            if(str1[i]=='F'){
                bool same=true;
                int cnt=0;
                for(int j=0;j<m;j++){
                    if(str2[j]!=ans[i+j]){
                        same=false;
                    }
                    if(fixed[i+j]){
                        cnt++;
                    }
                }

                if(!same){
                    continue;
                }

                if(cnt==m){
                    return "";
                }

                bool changed=false;
                for(int j=m-1;j>=0;j--){      
                    if(str2[j]!=ans[i+j]){    
                        changed=true;
                        break;
                    }

                    if(!fixed[i+j]){
                        ans[i+j]=(str2[j]=='a' ? 'b':'a');
                        changed=true;
                        break;
                    }
                }
                if(!changed){
                    return "";
                }
            }
        }

        return ans;    
    }
};