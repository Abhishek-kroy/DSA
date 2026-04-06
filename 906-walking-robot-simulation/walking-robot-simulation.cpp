// class Solution {
// public:
//     int robotSim(vector<int>& commands, vector<vector<int>>& obs) {
//         set<pair<int,int>> obstacles;
//         for (const auto& o : obs) {
//             obstacles.insert({o[0], o[1]});
//         }
//         int dist=0;
//         int x=0;
//         int y=0;
//         char direc='N';
//         for(auto i:commands){
//             if(i==-2){
//                 if(direc=='N'){
//                     direc='W';
//                 }
//                 if(direc=='W'){
//                     direc='S';
//                 }
//                 if(direc=='S'){
//                     direc='E';
//                 }
//                 if(direc=='E'){
//                     direc='N';
//                 }
//             }
//             else if(i==-1){
//                 if(direc=='N'){
//                     direc='E';
//                 }
//                 if(direc=='E'){
//                     direc='S';
//                 }
//                 if(direc=='S'){
//                     direc='W';
//                 }
//                 if(direc=='W'){
//                     direc='N';
//                 }                
//             }
//             else{
//                 if(direc=='N'){
//                     for(int j=1;j<=i;j++){
//                         if(obstacles.find({x,y+1}) != obstacles.end()){
//                             break;
//                         }
//                         y++;
//                         dist=max(dist, static_cast<int>(pow(x,2)+pow(y,2)) );
//                     }
//                 }
//                 if(direc=='S'){
//                     for(int j=1;j<=i;j++){
//                         if(obstacles.find({x,y-1}) != obstacles.end()){
//                             break;
//                         }
//                         y--;
//                         dist=max(dist,static_cast<int>(pow(x,2)+pow(y,2)));
//                     }
//                 }
//                 if(direc=='E'){
//                     for(int j=1;j<=i;j++){
//                         if(obstacles.find({x+1,y}) != obstacles.end()){
//                             break;
//                         }
//                         x++;
//                         dist=max(dist,static_cast<int>(pow(x,2)+pow(y,2)));
//                     }
//                 }
//                 if(direc=='W'){
//                     for(int j=1;j<=i;j++){
//                         if(obstacles.find({x-1,y}) != obstacles.end()){
//                             break;
//                         }
//                         x--;
//                         dist=max(dist,static_cast<int>(pow(x,2)+pow(y,2)));
//                     }
//                 }
                
//             }
//         }
//         return dist;
//     }
// };
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obs) {
        set<pair<int, int>> obstacles;
        for (const auto& o : obs) {
            obstacles.insert({o[0], o[1]});
        }

        int dist = 0;
        int x = 0, y = 0;
        char direc = 'N';

        for (auto i : commands) {
            if (i == -2) {
                if (direc == 'N') {
                    direc = 'W';
                } else if (direc == 'W') {
                    direc = 'S';
                } else if (direc == 'S') {
                    direc = 'E';
                } else if (direc == 'E') {
                    direc = 'N';
                }
            } else if (i == -1) {
                if (direc == 'N') {
                    direc = 'E';
                } else if (direc == 'E') {
                    direc = 'S';
                } else if (direc == 'S') {
                    direc = 'W';
                } else if (direc == 'W') {
                    direc = 'N';
                }
            } else {
                if (direc == 'N') {
                    for (int j = 1; j <= i; j++) {
                        if (obstacles.find({x, y + 1}) != obstacles.end()) {
                            break;
                        }
                        y++;
                        dist = max(dist, x * x + y * y);
                    }
                } else if (direc == 'S') {
                    for (int j = 1; j <= i; j++) {
                        if (obstacles.find({x, y - 1}) != obstacles.end()) {
                            break;
                        }
                        y--;
                        dist = max(dist, x * x + y * y);
                    }
                } else if (direc == 'E') {
                    for (int j = 1; j <= i; j++) {
                        if (obstacles.find({x + 1, y}) != obstacles.end()) {
                            break;
                        }
                        x++;
                        dist = max(dist, x * x + y * y);
                    }
                } else if (direc == 'W') {
                    for (int j = 1; j <= i; j++) {
                        if (obstacles.find({x - 1, y}) != obstacles.end()) {
                            break;
                        }
                        x--;
                        dist = max(dist, x * x + y * y);
                    }
                }
            }
        }

        return dist;
    }
};