class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> p;
        queue<int> n;
        for(auto v:nums){
            if(v>0){
                p.push(v);
            }
            else{
                n.push(v);
            }
        }
        int nu=nums.size()/2;
        vector<int> ans(2*nu);
        for(int i=0;i<2*nu;i+=2){
            ans[i]=p.front();
            p.pop();
            ans[i+1]=n.front();
            n.pop();
        }
        return ans;
    }
};