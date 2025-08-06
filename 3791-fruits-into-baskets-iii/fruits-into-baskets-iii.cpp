class maxSegmentTree {
    public :
    vector<int> tree;
    int n;
    maxSegmentTree(vector<int>& nums){
        n=nums.size();
        tree.resize(4*n);
        build(nums,0,n-1,0);
    }

    void build(vector<int> &nums,int l,int r,int node){
        if(l==r){
            tree[node]=nums[l];
            return ;
        }

        int mid=l+(r-l)/2;

        build(nums,l,mid,2*node+1);
        build(nums,mid+1,r,2*node+2);

        tree[node]=max(tree[2*node+1],tree[2*node+2]);
    }

    void update(int index,int val,int l,int r,int node){
        if(l==r){
            tree[node]=val;
            return ;
        }

        int mid=l+(r-l)/2;

        if(index<=mid){
            update(index,val,l,mid,2*node+1);
        }
        else{
            update(index,val,mid+1,r,2*node+2);
        }

        tree[node]=max(tree[2*node+1],tree[2*node+2]);
    }

    int getmax(int val,int l,int r,int node){
        if(tree[node]<val)  return -1;
        if(l==r){
            return l;
        }

        int mid=l+(r-l)/2;
        int left=getmax(val,l,mid,2*node+1);
        if(left!=-1)    return left;

        return getmax(val,mid+1,r,2*node+2);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        maxSegmentTree* t=new maxSegmentTree(baskets);
        int n=baskets.size();

        int unplaced=0;
        for(auto f:fruits){
            int idx=t->getmax(f,0,n-1,0);
            if(idx==-1) unplaced++;
            else{
                t->update(idx,-1,0,n-1,0);
            }
        }

        return unplaced;
    }
};