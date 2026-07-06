class Solution {
public:
    int dfs(vector<vector<int>>& adj,int node,int par,vector<int>& h){
        int hei=0;

        for(auto ch:adj[node]){
            if(ch!=par){
                hei=max(hei,dfs(adj,ch,node,h));
            }
        }

        h[node]=1+hei;

        return h[node];
    }

    void dfs2(vector<vector<int>>& adj,int node,int par,vector<int>& h,int hei,vector<int>& ans){
        int lar=-1;
        int lnode=-1;
        int slar=-1;

        for(auto ch:adj[node]){
            if(ch==par) continue;

            if(h[ch]>=lar){
                slar=lar;
                lar=h[ch];
                lnode=ch;
            }
            else if(h[ch]>slar){
                slar=h[ch];
            }
        } 

        ans[node]=max(h[node],hei+1);

        for(auto ch:adj[node]){
            if(ch==par) continue;

            int newHei;

            if(ch!=lnode){
                newHei=1+max(lar,hei);
            }
            else{
                newHei=1+max(slar,hei);
            }

            dfs2(adj,ch,node,h,newHei,ans);
        }
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> h(n);

        dfs(adj,0,-1,h);

        vector<int> ans(n,0);

        dfs2(adj,0,-1,h,0,ans);          

        vector<int> res;

        int mini=*min_element(ans.begin(),ans.end());

        for(int i=0;i<n;i++){

            if(ans[i]==mini){
                res.push_back(i); 
            }
        }

        return res;            
    }
};  