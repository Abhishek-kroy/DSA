class Solution {
public:
    bool check(vector<int>& reachable,int l,int r){
        int left=0;
        int right=reachable.size()-1;

        while(left<=right){
            int mid=left+(right-left)/2;

            if(reachable[mid]>=l && reachable[mid]<=r){
                return true; 
            }
            else if(reachable[mid]>r){
                left=mid+1;
            }
            else{
                right=mid-1; 
            }
        }

        return false; 
    }

    bool canReach(string s, int minJump, int maxJump) {

        int n=s.size();

        if(s[n-1]!='0'){
            return false; 
        }

        int i=n-2;

        vector<int> reachable;
        reachable.push_back(n-1);

        while(i>=0){

            if(s[i]=='0'){

                int l=i+minJump;
                int r=min(i+maxJump,n-1);

                if(check(reachable,l,r)){
                    reachable.push_back(i);
                }




            }

            i--;    


        }

        int l=reachable.size();

        if(reachable[l-1]!=0){
            return false;
        }

        return true; 
    }
};