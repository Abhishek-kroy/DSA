class dsu{
    public:
        vector<int> parent;
        int n;

        dsu(){
            n=20002;
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

        void unite(int r,int c){
            int ur=find(r);
            int uc=find(c);

            parent[uc]=ur;                         
        }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        dsu* d= new dsu();

        for(int i=0;i<stones.size();i++){
            int x=stones[i][0];
            int y=stones[i][1];

            d->unite(x,y+10001);         
        }

        unordered_set<int> s;

        for(int i=0;i<stones.size();i++){
            int x=stones[i][0];
            int y=stones[i][1];

            s.insert(d->find(x));
            s.insert(d->find(y+10001));
        }

        return (int)stones.size()-s.size();
        
    }
};