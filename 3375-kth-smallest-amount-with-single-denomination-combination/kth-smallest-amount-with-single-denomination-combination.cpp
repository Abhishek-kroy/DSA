class Solution {
public:
    long long lcm(int a,int b){
        return 1LL*a*b/__gcd(a,b);   
    }
    bool can(vector<int>& coins,int k,long long mid){
        long total=0;

        // for(auto c:coins){
        //     total+=(mid/(1LL*c)) ;         
        // }

        // if(total<k) return false;

        int n=coins.size();

        /*
            so first only one element at a time 
            then two element at a time 
            then three element at a time 
            and so on 
            and finally all n elements at a time 
            So use masking from 1 to 1<<n
        */

        long long limit=(1<<n);    
        for(long long i=1;i<limit;i++){      
            vector<int> d;  
            for(int j=0;j<n;j++){
                if(i&(1<<(j))){  
                    d.push_back(coins[j]);
                }
            }

            long long power=1;
            if(d.size()%2==0){
                power=-1; 
            }

            long long l=1;                                    
            for(auto di:d){
                l=lcm(l,di);
            }
            total+=(power*(mid/l));    
        }

        return total>=k; 
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long ans;
        long long l=1;
        long long r=LLONG_MAX;

        while(l<=r){
            long long mid=l+(r-l)/2;

            if(can(coins,k,mid)){
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