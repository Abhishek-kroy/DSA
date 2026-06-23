class dsu{
    public:
        vector<int> parent;
        vector<int> height;
        int n;

        dsu(int n){
            parent.resize(n+1);
            height.resize(n+1);

            for(int i=0;i<=n;i++){
                parent[i]=i;
                height[i]=1;
            }
        }

        int find(int u){
            if(parent[u]==u){
                return u;
            }

            return parent[u]=find(parent[u]); 
        }

        void unite(int u,int v){
            int up=find(u);
            int vp=find(v);

            if(up==vp){
                return ; 
            }

            if(height[up]>=height[vp]){
                parent[vp]=up;
                height[up]+=height[vp];
            }
            else{
                parent[up]=vp;
                height[vp]+=height[up];
            }
        }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n=isConnected.size();

        dsu* d=new dsu(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j])
                    d->unite(i+1,j+1);
            }
        }

        unordered_set<int> s;

        for(int i=1;i<=n;i++){
            s.insert(d->find(i));          
        }

        return s.size();
    }
};