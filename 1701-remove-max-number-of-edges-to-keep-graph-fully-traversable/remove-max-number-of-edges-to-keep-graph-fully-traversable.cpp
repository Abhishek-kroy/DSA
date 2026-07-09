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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        dsu* a=new dsu(n+1);
        dsu* b=new dsu(n+1);      

        int tot=0;
        int cnt=0;

        int cnt1=0;
        int cnt2=0;

        for(auto e:edges){

            tot++;  

            int t=e[0];

            if(t==3){
                int u=e[1];
                int v=e[2];

                int r1=a->find(u);
                int r2=a->find(v);

                if(r1!=r2){
                    a->unite(u,v);
                    b->unite(u,v);
                    cnt++; 
                    cnt1++;
                    cnt2++; 
                }
            }
        }

        for(auto e:edges){
            int t=e[0];

            if(t==1){
                int u=e[1];
                int v=e[2];

                int r1=a->find(u);
                int r2=a->find(v);

                if(r1!=r2){
                    a->unite(u,v);
                    cnt++; 
                    cnt1++; 
                }
            }
            if(t==2){
                int u=e[1];
                int v=e[2];

                int r1=b->find(u);
                int r2=b->find(v);

                if(r1!=r2){
                    b->unite(u,v);
                    cnt++; 
                    cnt2++; 
                }
            }
        }

        if(cnt1!=n-1 || cnt2!=n-1){    
            return -1;          
        }

        return tot-cnt; 


    }
};