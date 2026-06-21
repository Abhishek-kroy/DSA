class TreeAncestor {
        unordered_map<int,vector<int>> adj;

        unordered_map<int,vector<int>> up;    

        int n;
        int log;

public:

    void getup(int node,int par,unordered_map<int,vector<int>>& adj,unordered_map<int,vector<int>>& up){
        up[node].resize(log+1);

        for(int i=0;i<=log;i++){
            if(i>0){
                up[node][i]=up[up[node][i-1]][i-1];
            }
            else{
                up[node][i]=par;
            }
        }

        for(auto ch:adj[node]){
            getup(ch,node,adj,up);
        }
    }

    TreeAncestor(int n, vector<int>& parent) {
        for(int i=0;i<parent.size();i++){
            adj[parent[i]].push_back(i);            
        }

        this->n=n;

        log=log2(n)+1;

        up[-1].resize(log+1); 

        for(int i=0;i<=log;i++){
            up[-1][i]=-1;          
        }

        getup(0,-1,adj,up);            


    }
    
    int getKthAncestor(int node, int k) {
        for(int i=log;i>=0;i--){
            if(k&(1<<i)){
                node=up[node][i];
            }
        }                

        return node; 
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */