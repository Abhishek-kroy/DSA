class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // if(query_row==0){
        //     return min((double)1.00,(double)poured);     
        // }  

        vector<double> cur;
        cur.push_back((double)poured);  

        for(int row=1;row<=query_row;row++){      
            int n=cur.size();
            vector<double> next(n+1,0);

            for(int i=0;i<n;i++){
                double excess=max(0.00,double(cur[i]-1.00));   
                next[i]+=excess/(double)2;    
                next[i+1]+=excess/(double)2;
            }
            cur=next;
        }
        
        double q=cur[query_glass];          

        return min((double)1,q);    
    }
};