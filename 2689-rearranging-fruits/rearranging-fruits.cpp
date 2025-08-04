class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> b1;
        unordered_map<int,int> b2;
        int min_val=INT_MAX;
        for(auto v:basket1){
            min_val=min(min_val,v);
            b1[v]++;
        }
        for(auto v:basket2){
            min_val=min(min_val,v);
            b2[v]++;
        }
        vector<int> f;
        for(auto p:b1){
            int cnt1=p.second;
            int cnt2=b2[p.first];
            if(cnt1>cnt2){
                if((cnt1-cnt2)%2==0){
                    int c=(cnt1-cnt2)/2;
                    while(c--)
                        f.push_back(p.first);
                }
                else{
                    return -1;
                }
            }
        }
        for(auto p:b2){
            int cnt2=p.second;
            int cnt1=b1[p.first];
            if(cnt1<cnt2){
                if((cnt2-cnt1)%2==0){
                    int c=(cnt2-cnt1)/2;
                    while(c--)
                    f.push_back(p.first);
                }
                else{
                    return -1;
                }
            }
        }
        if(f.size()%2)  return -1;

        sort(f.begin(),f.end());

        int i=0;
        int j=f.size()-1;
        long long a=0;
        while(i<j){
            a+=min(1LL*f[i],1LL*2*min_val);
            i++;
            j--;
        }

        return a;
    }
};