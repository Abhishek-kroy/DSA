class Solution {
public:
    bool check(string s,string p,vector<int>& removable,int len){
        vector<int> take((int)s.size(),1);        

        for(int i=0;i<len;i++){
            take[removable[i]]=0;
        }

        int i=0;
        int j=0;

        while(i<(int)s.size() && j<(int)p.size()){
            if(!take[i]){
                i++;
                continue;
            }
            if(s[i]==p[j]){
                j++;
            }
            i++;
        }

        return j==(int)p.size();        
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {

        int l=0;
        int r=(int)removable.size();

        while(l<=r){
            int mid=l+(r-l)/2;

            if(check(s,p,removable,mid)){        
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }

        return r; 
    }
};