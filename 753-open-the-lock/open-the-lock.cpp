class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target=="0000"){
            return 0;
        }

        unordered_set<string> s;
        for(auto d:deadends){
            s.insert(d);
        }

        if(s.find("0000")!=s.end()){
            return -1;
        }

        unordered_map<string,bool> vis;    

        queue<string> q;
        q.push("0000");

        vis["0000"]=true;

        int l=0; 

        while(!q.empty()){

            int sz=q.size();

            while(sz--){
                auto str=q.front();
                q.pop();

                if(str==target){
                    return l; 
                }

                if(s.find(str)!=s.end()){
                    continue; 
                }

                for(int i=0;i<4;i++){
                    char c=str[i];

                    char pc=(c-'0'+9)%10+'0';

                    char nc=(c-'0'+1)%10+'0';         

                    string nstr=str;
                    nstr[i]=pc;

                    if(vis.find(nstr)==vis.end()){
                        vis[nstr]=true;                                                                        
                        q.push(nstr);
                    }

                    nstr[i]=nc;
                    if(vis.find(nstr)==vis.end()){
                        vis[nstr]=true;                                                                        
                        q.push(nstr);
                    }
                }

            }
            l++;         
        }

        return -1; 
    }
};