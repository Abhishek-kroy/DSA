class Solution {
public:
    void dfs1(int n, vector<vector<int>>& adj,vector<int>& height,int node,int par){            
        for(auto ch:adj[node]){
            if(ch==par){
                continue;
            }

            dfs1(n,adj,height,ch,node);
            height[node]=max(height[node],1+height[ch]);
        }
    }

    void dfs2(int n, vector<vector<int>>& adj,vector<int>& height,int& h,vector<int>& ans,int node,int par,int outsidehei){
        int nh=max(height[node],outsidehei);
        if(nh<h){
            ans.clear();
            ans.push_back(node);

            h=nh;
        }
        else if(nh==h){
            ans.push_back(node);
        }

        vector<int> maxh(2,0);
        for(auto ch:adj[node]){
            if(ch==par){
                continue;
            }
            int hh=1+height[ch];    
            if(hh>maxh[0]){
                maxh[1]=maxh[0];
                maxh[0]=hh;            
            }
            else if(hh>maxh[1]){
                maxh[1]=hh;
            }
        }

        for(auto ch:adj[node]){
            if(ch==par){
                continue;
            }

            int noutsidehei=1+max(outsidehei,1+height[ch]==maxh[0]? maxh[1]:maxh[0]);

            dfs2(n,adj,height,h,ans,ch,node,noutsidehei);
        }
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> height(n,0);
        dfs1(n,adj,height,0,-1);    
        vector<int> ans;
        int h=height[0];

        dfs2(n,adj,height,h,ans,0,-1,-1);

        return ans;
    }
};