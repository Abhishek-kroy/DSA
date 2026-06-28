class dsu{
    public:
        vector<int> parent;
        int n;

        dsu(int _n){
            n=_n;
            parent.resize(n);

            for(int i=0;i<n;i++){
                parent[i]=i; 
            }
        }        

        int find(int v){
            if(parent[v]==v){
                return v;
            }

            return parent[v]=find(parent[v]);
        }

        void unite(int u,int v){
            int up=find(u);
            int vp=find(v);

            parent[vp]=up;                
        }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        dsu* d=new dsu(s.size());

        for(auto p:pairs){
            d->unite(p[0],p[1]);
        }                

        unordered_map<int,vector<char>> f;
        unordered_map<int,int> ptr;

        for(int i=0;i<s.size();i++){
            f[d->find(i)].push_back(s[i]);
            ptr[d->find(i)]=0;
        }

        for(auto& [k,v]:f){
            sort(v.begin(),v.end());
        }

        string ans="";

        for(int i=0;i<s.size();i++){
            ans+=f[d->find(i)][ptr[d->find(i)]];
            ptr[d->find(i)]++;                        
        }

        return ans;
    }
};