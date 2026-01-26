class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<vector<int>> a;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>=0)
                a.push_back({nums[i],i});  
        }  

        if(a.size()==0){
            return nums;     
        }

        k=k%(a.size());

        for(int i=0;i<a.size()/2;i++){        
            swap(a[i][0],a[a.size()-1-i][0]);
        }

        int _n=a.size();

        int st=_n-k;  
        int i=st;
        int j=a.size()-1;

        while(i<j){  
            swap(a[i][0],a[j][0]);
            i++;
            j--;
        }

        i=0;
        j=st-1;
        while(i<j){
            swap(a[i][0],a[j][0]);
            i++;
            j--;   
        }

        
        j=0;

        for(int i=0;i<a.size();i++){
            nums[a[i][1]]=a[i][0];
        }

        return nums;   



        //  1 2 3 4
        // 4 1 2 3 
        // 4 3 2 1  

    }
};