class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<vector<int>> r(n,vector<int> (4));

        for(int i=0;i<n;i++){
            r[i]={positions[i],healths[i],directions[i],i};
        }

        sort(r.begin(),r.end());

        stack<int> R;
        stack<int> L;



        for(int i=0;i<n;i++){
            int pos=r[i][0];
            int health=r[i][1];
            char dir=r[i][2];

            if(dir=='L'){
                while(!R.empty()){
                    int ind=R.top();
                    R.pop();

                    int health2=r[ind][1];
                    if(health2!=health){
                        if(health2<health){
                            r[ind][1]=0;
                            health--;
                            r[i][1]--;
                        }
                        else{
                            r[i][1]=0;  
                            health=0; 
                            r[ind][1]--;
                            health2--;
                            if(health2>0){
                                R.push(ind);
                                break;
                            }
                        }
                    }
                    else{
                        r[i][1]=0;
                        health=0;
                        health2=0;
                        r[ind][1]=0;
                        break;
                    }
                }
                if(health>0){
                    L.push(i);
                }
            }
            if(dir=='R'){
                // while(!L.empty()){
                //     int ind=L.top();
                //     L.pop();

                //     int health2=r[ind][1];
                //     if(health2!=health){
                //         if(health2<health){
                //             r[ind][1]=0;
                //             r[i][1]--;
                //             health--;
                //         }
                //         else{
                //             r[i][1]=0;
                //             health=0;
                //             r[ind][1]--;
                //             health2--;
                //             if(health2>0){
                //                 L.push(ind);
                //                 break;
                //             }
                //         }
                //     }
                //     else{
                //         r[i][1]=0;
                //         health=0;
                //         health2=0;
                //         r[ind][1]=0;
                //         break;
                //     }
                // }   

                if(health>0){
                    R.push(i);
                }
            }
        }

        vector<vector<int>> ans;   

        while(!R.empty()){
            int ind=R.top();
            R.pop();
            ans.push_back({r[ind][3],r[ind][1]});            
        }
        while(!L.empty()){
            int ind=L.top();
            L.pop();
            ans.push_back({r[ind][3],r[ind][1]});            
        }

        sort(ans.begin(),ans.end());

        vector<int> res;

        for(auto v:ans){
            res.push_back(v[1]);
        }

        return res;   




    }
};