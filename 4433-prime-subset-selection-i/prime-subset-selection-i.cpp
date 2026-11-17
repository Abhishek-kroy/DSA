class Solution {
public:
    static vector<int> isprime;
    static vector<int> primes;

    static bool proc;

    void sieve(){

        proc=true;

        isprime.assign(1e6+2,1);        

        isprime[0]=0;
        isprime[1]=0;   

        for(int i=2;i<1e6+1;i++){
            if(isprime[i]){
                primes.push_back(i);
                for(long long j=1LL*i*i;j<=1LL*1e6+1;j+=i){
                    isprime[j]=0;
                }
            }
        } 
    }

    vector<int> maxPrimes(int n, int s) {

        if(!proc){
            sieve();
        }

        vector<int> ans;

        for(auto p:primes){
            if(p>n){
                break;    
            }
            if((s-p)>=0){
                ans.push_back(p);
                s-=p;
            }
        }

        return ans;        
    }
};

bool Solution::proc=false;
vector<int> Solution::isprime;
vector<int> Solution::primes;    