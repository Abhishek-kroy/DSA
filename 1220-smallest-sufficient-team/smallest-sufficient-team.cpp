class Solution {
public:
    vector<vector<pair<int,vector<int>>>> dp;
    vector<vector<int>> vis;

    pair<int,vector<int>> getans(unordered_map<string,int>& req,
                                 int reqmask,
                                 vector<vector<string>>& people,
                                 int i){

        int n=req.size();
        int m=people.size();

        if(reqmask==((1<<n)-1)){
            return {0,{}};
        }

        if(i>=m){
            return {1000000,{}};
        }

        if(vis[i][reqmask]) return dp[i][reqmask];
        vis[i][reqmask]=1;

        int minnum=1000000;
        vector<int> best;

        // Not take
        auto [num,peoples]=getans(req,reqmask,people,i+1);
        if(num<minnum){
            minnum=num;
            best=peoples;
        }

        // Take
        int newMask=reqmask;
        for(auto &s:people[i]){
            if(req.count(s)){
                newMask |= (1<<req[s]);
            }
        }

        auto [num2,peoples2]=getans(req,newMask,people,i+1);
        num2++;

        if(num2<minnum){
            minnum=num2;
            best=peoples2;
            best.push_back(i);
        }

        return dp[i][reqmask]={minnum,best};
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills,
                                       vector<vector<string>>& people) {

        unordered_map<string,int> req;
        for(int i=0;i<req_skills.size();i++){
            req[req_skills[i]]=i;
        }

        int m=people.size();
        int states=1<<req_skills.size();

        dp.assign(m, vector<pair<int,vector<int>>>(states));
        vis.assign(m, vector<int>(states,0));

        return getans(req,0,people,0).second;
    }
};    