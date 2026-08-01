class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {

        unordered_set<int> visited;

        queue<int> q;

        q.push(x);
        visited.insert(x);        

        int l=0;

        while(!q.empty()){

            int sz=q.size();

            while(sz--){

                auto v=q.front();        

                q.pop();

                if(v==y){
                    return l;
                }    

                if((v%11)==0  && visited.find(v/11)==visited.end()){
                    visited.insert(v/11);
                    q.push(v/11);
                }
                if((v%5)==0  && visited.find(v/5)==visited.end()){
                    visited.insert(v/5);
                    q.push(v/5);
                }

                if(visited.find(v-1)==visited.end()){
                    visited.insert(v-1);
                    q.push(v-1);
                }

                if(visited.find(v+1)==visited.end()){
                    visited.insert(v+1);
                    q.push(v+1);
                }
            }

            l++;    
        }

        return -1;        
    }
};