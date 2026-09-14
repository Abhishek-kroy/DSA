class Solution {
public:
    int getcnt(string& str){
        int cnt=0;
        for(auto c:str){
            if(c!=' '){
                cnt++;                                                                                
            }
        }

        return cnt;        
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size();

        vector<string> ans;

        string t=words[0];

        for(int i=1;i<n;i++){
            string str=words[i];
            int len=str.size();
            if(t.size()!=0){
                len++;
            }

            if(t.size()+len<=maxWidth){
                t=t+" "+str;              
            }
            else{
                ans.push_back(t);
                t=str;
            }
        }         

        ans.push_back(t);

        for(int i=0;i<(int)ans.size()-1;i++){
            string str=ans[i];
            int ch=getcnt(str);
            int space=max(1,(int)str.size()-ch);

            int dis=(maxWidth-(ch))/(space);
            int starting=(maxWidth-(ch))%(space);

            // cout<<i<<" space "<<dis<<" starting "<<starting<<endl;

            int se=1;
            string nstr="";
            int j=0;
            while(j<str.size()){
                while(j<str.size() && str[j]!=' '){
                    nstr+=str[j];
                    j++;
                }

                int temp=dis+(se<=starting);

                while(nstr.size()<maxWidth && temp>0){
                    nstr+=" ";
                    temp--;
                }

                se++;    

                j++;
            }

            ans[i]=nstr;        
        }

        while(ans[ans.size()-1].size()<maxWidth){
            ans[ans.size()-1]+=" ";
        }

        return ans;           
    }
};