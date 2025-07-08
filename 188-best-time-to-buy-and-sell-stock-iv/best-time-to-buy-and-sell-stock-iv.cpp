class Solution {
public:
    map<pair<int,pair<int,bool>>,int> dp;
    int getans(int k, vector<int>& prices,bool buyed,int i=0){
        if(i>=prices.size() or k<=0){
            return 0;
        }

        if(dp.find({i,{k,buyed}})!=dp.end()){
            return dp[{i,{k,buyed}}];
        }

        int w1=INT_MIN,w2=INT_MIN,w3=INT_MIN;
        // buy
        if(!buyed){
            w1=max(w1,-prices[i]+getans(k,prices,true,i+1));
        }

        // sell
        if(buyed){
            w2=max(w2,prices[i]+getans(k-1,prices,false,i+1));
        }

        // skip
        w3=max(w3,getans(k,prices,buyed,i+1));

        return dp[{i,{k,buyed}}]=max({w1,w2,w3});
    }
    int maxProfit(int k, vector<int>& prices) {
        bool buyed=false;
        return getans(k,prices,buyed,0);
    }
};

/*


*/