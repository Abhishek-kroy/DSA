class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();

        int i=min_element(nums.begin(),nums.end())-nums.begin();
        int j=max_element(nums.begin(),nums.end())-nums.begin();

        if(i>j){
            swap(i,j);
        }


        int w1=(i+1)+(n-j);
        int w2=n-i;
        int w3=j+1;

        return min({w1,w2,w3});                
    }
};