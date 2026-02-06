class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int,vector<int>> adj;

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        t++;     

        adj[1].push_back(0);  

        queue<vector<double>> q;
        q.push({1,0,1});
        while(!q.empty() && t>0){
            t--; 
            int s=q.size();
            while(s--){
                vector<double> v=q.front();     
                q.pop();

                double node=v[0];

                if(node==target){
                    if(t!=0 && (adj[node].size()-1)>0){    
                        return 0;     
                    }
                    return v[2];     
                }
                double par=v[1];   
                double l=v[2]*((double)1/((double)(adj[node].size()-1)));  


                for(double ch:adj[node]){   
                    if(ch!=par){
                        q.push({ch,node,l});
                    }
                }
            }   
        }

        return 0;       

    }
};