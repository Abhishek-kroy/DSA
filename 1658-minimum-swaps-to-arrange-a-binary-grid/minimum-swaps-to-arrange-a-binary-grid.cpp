#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> seg;
    int n;

    void build(int node,int l,int r,vector<int>& a){

        if(l==r){
            seg[node]=a[l];
            return;
        }

        int mid=(l+r)/2;

        build(node*2,l,mid,a);
        build(node*2+1,mid+1,r,a);

        seg[node]=max(seg[node*2],seg[node*2+1]);
    }

    int query(int node,int l,int r,int ql,int need){

        if(r<ql || seg[node]<need) return -1;

        if(l==r) return l;

        int mid=(l+r)/2;

        int left=query(node*2,l,mid,ql,need);

        if(left!=-1) return left;

        return query(node*2+1,mid+1,r,ql,need);
    }

    void update(int node,int l,int r,int idx){

        if(l==r){
            seg[node]=-1;
            return;
        }

        int mid=(l+r)/2;

        if(idx<=mid) update(node*2,l,mid,idx);
        else update(node*2+1,mid+1,r,idx);

        seg[node]=max(seg[node*2],seg[node*2+1]);
    }

    int getzer(vector<int>& v){

        int cnt=0;

        for(int i=v.size()-1;i>=0;i--){
            if(v[i]==0) cnt++;
            else break;
        }

        return cnt;
    }

    int minSwaps(vector<vector<int>>& grid) {

        n=grid.size();

        vector<int> z(n);

        for(int i=0;i<n;i++)
            z[i]=getzer(grid[i]);

        seg.resize(4*n);

        build(1,0,n-1,z);

        set<int> ind;

        int ans=0;

        for(int i=0;i<n;i++){

            int need=n-1-i;

            int index=query(1,0,n-1,0,need);

            if(index==-1) return -1;

            int original=index;

            int shift=distance(ind.lower_bound(index),ind.end());

            index+=shift;

            ans+=(index-i);

            ind.insert(original);

            update(1,0,n-1,original);
        }

        return ans;
    }
};    