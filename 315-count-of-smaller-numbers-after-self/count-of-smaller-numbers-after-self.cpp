class Solution {
public:
    vector<int> ans;
    void mergesort(vector<vector<int>>& nums,int i,int j){
        if(i>=j){
            return  ; 
        }

        int mid=i+(j-i)/2;


        mergesort(nums,i,mid);        
        mergesort(nums,mid+1,j);

        vector<vector<int>>       res(j-i+1);
        int k=0;

        int i1=i;
        int i2=mid+1;

        while(i1<=mid && i2<=j){    
            if(nums[i1][0]<=nums[i2][0]){
                ans[nums[i1][1]]+=i2-(mid+1);                          
                res[k]=nums[i1];
                i1++;
            }
            else{
                res[k]=nums[i2];
                i2++;
            }

            k++; 
        }

        while(i1 <= mid){
            ans[nums[i1][1]] += i2 - (mid + 1);  
            res[k] = nums[i1];

            i1++;

            k++;
        }

        while(i2 <= j){
            res[k] = nums[i2];

            i2++;

            k++; 
        }

        for(int k=0;k<j-i+1;k++){
            nums[k+i]=res[k];
        }   

    }
    vector<int> countSmaller(vector<int>& num) {
        ans.assign((int)num.size(),0);           

        vector<vector<int>> nums((int)num.size());
        

        for(int i=0;i<(int)num.size();i++){
            nums[i]={num[i],i};
        }

        mergesort(nums,0,(int)nums.size()-1);          

        return ans;        

    }
};