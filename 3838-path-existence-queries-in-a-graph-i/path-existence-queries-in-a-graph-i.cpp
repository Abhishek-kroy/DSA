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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        dsu d(n);



        int i=0;

        while(i<n){
            int j=i+1;

            while(j<n && nums[j]-nums[j-1]<=maxDiff){
                d.unite(j-1,j);

                j++; 
            }

            i=j;
        }

        vector<bool> ans; 

        for(auto q:queries){
            int u=q[0];
            int v=q[1];           

            if(d.find(u)==d.find(v)){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);            
            }
        }

        return ans;      
    }
};