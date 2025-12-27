#define ll long long 
#define ti pair<ll,int> 
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end()); 
        int mostusedroom=0;
        unordered_map<int,long long> used; 
        long long f=0;
        priority_queue<ll,vector<ll>,greater<ll>> freerooms;
        for(int i=0;i<n;i++){
            freerooms.push(i);
        }

        priority_queue<ti,vector<ti>,greater<ti>> occupiedrooms; 

        long long t=0;

        for(auto v:meetings){
            long long st=v[0];
            long long end=v[1];

            t=st;

            while(!occupiedrooms.empty()){
                auto [t1,room]=occupiedrooms.top();

                if(t1>t)    break;
                else{
                    freerooms.push(room);
                    occupiedrooms.pop(); 
                }
            }

            if(freerooms.size()==0){
                auto [t1,room]=occupiedrooms.top(); 
                occupiedrooms.pop(); 
                freerooms.push(room); 
                t=t1;
            }

            int room=freerooms.top();
            freerooms.pop();

            long long dur=end-st;

            used[room]++;
            if(used[room]>f){
                mostusedroom=room;
                f=used[room]; 
            }
            if(used[room]==f && room<mostusedroom){ 
                mostusedroom=room;
                // f=used[room];   
            }

            occupiedrooms.push({t+dur,room}); 

        }


        return mostusedroom; 
    }
};