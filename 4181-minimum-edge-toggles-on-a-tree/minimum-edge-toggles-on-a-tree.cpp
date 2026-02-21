class Solution {
public:
    void getans(int n,vector<vector<pair<int,int>>>& adj,string& start, string& target,int node,int par,int ed,vector<int>& res){        


        for(auto v:adj[node]){
            int ch=v.first;
            int edge=v.second;
            if(ch!=par){
                getans(n,adj,start,target,ch,node,edge,res);  
            }
        }                                              

        if(start[node]!=target[node]){
            if(node!=0){
                res.push_back(ed);
                start[node]=(start[node]=='0' ? '1':'0');    
                start[par]=(start[par]=='0' ? '1':'0');  
            }
            else{
                res={-1};
            }
        }                                                       
    }

    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        vector<vector<pair<int,int>>> adj(n);
        int c = 0;
        for(auto &e : edges){
            adj[e[0]].push_back({e[1], c});
            adj[e[1]].push_back({e[0], c});
            c++;
        }  

        int cnt=0;

        for(int i=0;i<n;i++){
            if(start[i]!=target[i]){
                cnt++;
            }
        }

        if(cnt%2){
            return {-1};
        }

        vector<int> res;

        getans(n,adj,start,target,0,-1,-1,res);     

        sort(res.begin(),res.end())    ;         

        return res ; 
    }
};