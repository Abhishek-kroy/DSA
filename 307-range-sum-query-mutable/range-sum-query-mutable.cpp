class NumArray {
    int n;
    vector<int> tree;
public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        tree.resize(4*n);

        build(nums,0,0,n-1);        
    }

    void build(vector<int>& nums,int i,int l,int r){
        if(l==r){
            tree[i]=nums[l];
            return ; 
        }

        int mid=l+(r-l)/2;

        build(nums,2*i+1,l,mid);

        build(nums,2*i+2,mid+1,r);

        tree[i]=tree[2*i+1]+tree[2*i+2]; 
    }

    void getupdate(int index,int val,int i,int l,int r){
        if(l==r){
            tree[i]=val;
            return ;
        }

        int mid=l+(r-l)/2;

        if(index<=mid){
            getupdate(index,val,2*i+1,l,mid);
        }
        else{
            getupdate(index,val,2*i+2,mid+1,r);
        }

        tree[i]=tree[2*i+1]+tree[2*i+2];
    }
    
    void update(int index, int val) {
        getupdate(index,val,0,0,n-1);
    }

    int getsum(int i,int l,int r,int left,int right){
        if(l>right || r<left){
            return 0;
        }  

        if(left<=l && right>=r){      
            return tree[i];        
        }

        int mid=l+(r-l)/2;

        return getsum(2*i+1,l,mid,left,right)+getsum(2*i+2,mid+1,r,left,right); 
    }
    
    int sumRange(int left, int right) {
        return getsum(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */