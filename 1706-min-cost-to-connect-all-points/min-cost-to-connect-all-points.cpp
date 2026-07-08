class dsu{
    public:
        int n;
        vector<int> parent;
        vector<int> size;

        dsu(int _n){
            n=_n;

            parent.resize(n);
            size.resize(n);

            for(int i=0;i<n;i++){
                parent[i]=i;
                size[i]=1;
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

            if(size[up]>=size[vp]){
                parent[vp]=up;
                size[up]+=size[vp];
            }
            else{
                parent[up]=vp;
                size[vp]+=size[up];                      
            }


        }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();          

        vector<vector<int>> edges;          




        for(int i=0;i<n;i++){
            int x=points[i][0];
            int y=points[i][1];
            for(int j=i;j<n;j++){
                int x2=points[j][0];
                int y2=points[j][1];
                edges.push_back({abs(x-x2)+abs(y-y2),i,j});
            }
        }


        sort(edges.begin(),edges.end()); 

        dsu* d= new dsu(n); 

        int ans=0;  
        for(auto e:edges){
            int wt=e[0];
            int u=e[1];
            int v=e[2];

            if(d->find(u)!=d->find(v)){
                d->unite(u,v);

                ans+=wt;
            }
        }

        return ans;        


    }
};