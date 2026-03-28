class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        int n=source.size();

        int i=0;
        int j=0;
        for(i=0;i<n;i++){
            string res="";    
            for(j=0;j<source[i].size();j++){

                if(source[i][j]=='/'){
                    if(source[i][j+1]=='/'){
                        break;                                   
                    }
                    else if(source[i][j+1]=='*'){    
                        j++;    
                        j++;
                        bool found=false;
                        for(i;i<n;i++){
                            for(j;j<source[i].size();j++){
                                if(source[i][j]=='*' && j+1<source[i].size() && source[i][j+1]=='/'){
                                    j++; 
                                    found=true;
                                    break;

                                }
                            }
                            if(found){
                                break;
                            }
                            j=0;   
                        }
                    }
                    else{
                        res+=source[i][j];
                    }
                }
                else{
                    res+=source[i][j];    
                }

            }

            if(res.size())
                ans.push_back(res);    

            j=0;
        }

        return ans;   
    }
};