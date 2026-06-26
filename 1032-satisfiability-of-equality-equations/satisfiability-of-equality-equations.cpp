class dsu{
    public:
    vector<int> parent;    
    vector<int> size;    

    int n;

    dsu(int n){
        this->n=n;
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
    bool equationsPossible(vector<string>& equations) {
        dsu* d=new dsu(26);

        for(auto eq:equations){
            int a=eq[0]-'a';
            int b=eq[3]-'a';

            if(eq[1]=='!'){
                int up=d->find(a);
                int vp=d->find(b);

                if(up==vp){
                    return false;
                }
            }
            else{
                d->unite(a,b);
            }
        }
        for(auto eq:equations){
            int a=eq[0]-'a';
            int b=eq[3]-'a';

            if(eq[1]=='!'){
                int up=d->find(a);
                int vp=d->find(b);

                if(up==vp){
                    return false;
                }
            }  
        }

        return true; 
    }
};