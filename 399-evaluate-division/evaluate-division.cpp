class dsu{
public:
    vector<int> parent;
    vector<int> size;
    vector<double> wt;

    int n;

    dsu(int _n){
        n=_n;
        parent.resize(n);
        size.resize(n);
        wt.resize(n);

        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
            wt[i]=1.0;
        }
    }

    int find(int u){
        if(parent[u]==u)
            return u;

        int curr=parent[u];
        parent[u]=find(parent[u]);
        wt[u]*=wt[curr];

        return parent[u];
    }

    void unite(int u,int v,double w){
        int up=find(u);
        int vp=find(v);

        if(up==vp)
            return;

        parent[up]=vp;
        wt[up]=(w*wt[v])/wt[u];
        size[vp]+=size[up];
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        unordered_map<string,int> mp;
        int id=0;

        for(auto &eq:equations){
            if(!mp.count(eq[0])) mp[eq[0]]=id++;
            if(!mp.count(eq[1])) mp[eq[1]]=id++;
        }

        dsu *d=new dsu(id);

        for(int i=0;i<equations.size();i++){
            d->unite(mp[equations[i][0]], mp[equations[i][1]], values[i]);
        }

        vector<double> ans;

        for(auto &q:queries){

            if(!mp.count(q[0]) || !mp.count(q[1])){
                ans.push_back(-1.0);
                continue;
            }

            int u=mp[q[0]];
            int v=mp[q[1]];


            int root1=d->find(u);
            int root2=d->find(v);          

            if(root1!=root2){
                ans.push_back(-1.0);
            }
            else{
                ans.push_back(d->wt[u]/d->wt[v]);
            }
        }

        return ans;
    }
}; 