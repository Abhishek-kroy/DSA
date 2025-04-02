class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        int cnt=0;
        while(i<g.size() and j<s.size()){
            int greed=g[i];
            while(j<s.size() and s[j]<greed){
                j++;
            }
            if(j<s.size())
                cnt++;
            i++;
            j++;
        }

        return cnt;
    }
};