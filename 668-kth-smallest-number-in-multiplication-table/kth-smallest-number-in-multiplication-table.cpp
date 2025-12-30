class Solution {
public:
    bool can(int m,int n,int k,long long mid){
        long long total=0;
        if(m>n){
            swap(m,n);
        }  


        for(int i=1;i<=m;i++){
            long long w=min(1LL*n,mid/(1LL*i));   
            if(w==0)    break;   

            long long jump=min(1LL*m,(1LL*mid)/w);  
            total+=((jump-i+1)*w);    
            i=jump; 
            if(total>=k)    return true ;     
        }

        return total>=k ; 
    }
    int findKthNumber(int m, int n, int k) {

        long long l=1;  
        long long r=k; 
        long long ans;  

        while(l<=r){
            long long mid=l+(r-l)/2;


            if(can(m,n,k,mid)){
                ans=mid; 
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return ans;   
    }
}; 