class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size()/2;
        int sz=2*n;



        int cnt=0;
                
        for(int i=0;i<sz-1;i+=2){
            int v=row[i];
            int pt;

            if(v%2==0){
                pt=v+1;                                
            }
            else{
                pt=v-1;
            }
            if(row[i+1]==pt){
                continue;
            }
            else{
                cnt++;
                for(int j=i+2;j<sz;j++){
                    if(row[j]==pt){
                        swap(row[i+1],row[j]);
                        break;
                    }
                }
            }
        }

        return cnt;
    }
};