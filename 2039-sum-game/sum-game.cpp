class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();

        int sum1=0;
        int sum2=0;
        int l=0;
        int r=0;

        for(int i=0;i<n/2;i++){
            if(num[i]>='0' && num[i]<='9'){
                sum1+=(num[i]-'0');
            }
            else{
                l++;
            }
        }
        for(int i=n/2;i<n;i++){
            if(num[i]>='0' && num[i]<='9'){
                sum2+=(num[i]-'0');
            }
            else{
                r++;
            }
        }

        int diff=abs(sum1-sum2);

        int t=abs(l-r);

        if((sum1>=sum2 && l>r) || (sum2>=sum1 && r>l)){
            return true;
        }        

        if(t%2){
            return true;    
        }

        if(diff==0){
            return false;
        }

        if(diff==(9*(t/2))){
            return false;
        }

        return true;     
    }
};