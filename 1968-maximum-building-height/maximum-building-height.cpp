class Solution {
public:
    int maxBuilding(int m, vector<vector<int>>& restrictions) {
        restrictions.insert(restrictions.begin(),{1,0});
        restrictions.push_back({m, INT_MAX});           
            sort(restrictions.begin(),restrictions.end());

            int n=restrictions.size();      

            vector<int> v(n,INT_MAX);

            int ans=0;

            for(int i=0;i<n-1;i++){        

                int x1=restrictions[i][0];
                int h1=restrictions[i][1];
                int x2=restrictions[i+1][0];
                int h2=restrictions[i+1][1];

                int dist=x2-x1;

                int hdiff=abs(h2-h1);

                if(hdiff>=dist){
                    // ans=max(ans,min(h1,h2)+dist);
                    restrictions[i+1][1]=min(restrictions[i+1][1],min(h1,h2)+dist);
                }
                else{
                    // ans=max(ans,max(h1,h2)+(dist-hdiff)/2);
                }

            }                                                         
            for(int i=n-1;i>0;i--){        
                int x1=restrictions[i][0];
                int h1=restrictions[i][1];
                int x2=restrictions[i-1][0];
                int h2=restrictions[i-1][1];

                int dist=x1-x2;  

                int hdiff=abs(h2-h1);

                if(hdiff>=dist){
                    // ans=max(ans,min(h1,h2)+dist);
                    restrictions[i-1][1]=min(restrictions[i-1][1],min(h1,h2)+dist);
                }
                else{
                    // ans=max(ans,max(h1,h2)+(dist-hdiff)/2);                   
                }

            }                                       

            for(int i=0;i<n-1;i++){     
                 int x1=restrictions[i][0];
                int h1=restrictions[i][1];
                int x2=restrictions[i+1][0];
                int h2=restrictions[i+1][1];


                int dist=x2-x1;

                int hdiff=abs(h2-h1);

                ans=max(ans,max(h1,h2)+(dist-hdiff)/2);
            }

            return ans;                                          
    }
};