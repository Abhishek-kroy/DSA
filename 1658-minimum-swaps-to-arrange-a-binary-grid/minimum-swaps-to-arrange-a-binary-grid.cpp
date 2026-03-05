class Solution {
public:

    int n;
    vector<int> segmax, segsum;    

    void build(int node,int l,int r,vector<int>& a){

        if(l==r){
            segmax[node]=a[l];
            return;
        }

        int mid=(l+r)/2;

        build(node*2,l,mid,a);
        build(node*2+1,mid+1,r,a);

        segmax[node]=max(segmax[node*2],segmax[node*2+1]);
    }

    int querymax(int node,int l,int r,int need){

        if(segmax[node] < need) return -1;

        if(l==r) return l;

        int mid=(l+r)/2;

        if(segmax[node*2] >= need)
            return querymax(node*2,l,mid,need);

        return querymax(node*2+1,mid+1,r,need);
    }

    void updatemax(int node,int l,int r,int idx){

        if(l==r){
            segmax[node]=-1;
            return;
        }

        int mid=(l+r)/2;

        if(idx<=mid) updatemax(node*2,l,mid,idx);
        else updatemax(node*2+1,mid+1,r,idx);

        segmax[node]=max(segmax[node*2],segmax[node*2+1]);
    }      

    void updatesum(int node,int l,int r,int idx){

        if(l==r){
            segsum[node]=1;
            return;
        }

        int mid=(l+r)/2;

        if(idx<=mid) updatesum(node*2,l,mid,idx);
        else updatesum(node*2+1,mid+1,r,idx);

        segsum[node]=segsum[node*2]+segsum[node*2+1];
    }

    int querysum(int node,int l,int r,int ql,int qr){

        if(qr<l || r<ql) return 0;

        if(ql<=l && r<=qr) return segsum[node];

        int mid=(l+r)/2;

        return querysum(node*2,l,mid,ql,qr)
             + querysum(node*2+1,mid+1,r,ql,qr);
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

        segmax.resize(4*n);
        segsum.resize(4*n);

        build(1,0,n-1,z);

        int ans=0;

        for(int i=0;i<n;i++){

            int need=n-1-i;

            int index=querymax(1,0,n-1,need);

            if(index==-1) return -1;

            int shift=querysum(1,0,n-1,index+1,n-1);

            int adjusted=index+shift;

            ans+=(adjusted-i);

            updatemax(1,0,n-1,index);
            updatesum(1,0,n-1,index);
        }

        return ans;
    }
};    