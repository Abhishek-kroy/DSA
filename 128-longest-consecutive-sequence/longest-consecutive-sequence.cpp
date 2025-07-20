class D{
    public :
    int n;
    unordered_map<int,int> parent,size;
    D(int _n,vector<int>& nums){
        n=_n;
        for(int i=0;i<n;i++){
            parent[nums[i]]=nums[i];
            size[nums[i]]=1;
        }
    }

    int find(int node){
        if(parent[node]==node){
            return node;
        }

        return parent[node]=find(parent[node]);
    }

    void u(int n1,int n2){
        int u1=find(n1);
        int u2=find(n2);
        if(u1==u2)   return ;
        if(size[u1]>=size[u2]){
            parent[u2]=u1;
            size[u1]+=size[u2];
        }
        else if(size[u1]<size[u2]){
            parent[u1]=u2;
            size[u2]+=size[u1];
        }
    }
    
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        D* d=new D(nums.size(),nums);
        int n=nums.size();
        unordered_set<int> s(nums.begin(),nums.end());

        for(auto val:nums){
            if(s.find(val-1)!=s.end()){
                d->u(val,val-1);
            }
            if(s.find(val+1)!=s.end()){
                d->u(val,val+1);
            }
        }

        int ans=0;
        for(auto v:nums){
            ans=max(ans,d->size[v]);
        }

        return ans;
    }
};