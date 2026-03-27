class Solution {
public:
    int addMinimum(string word) {
        int n=word.size();

        string str="abc";

        int p1=0;

        int ans=0;  

        for(int i=0;i<n;i++){
            if(word[i]!=str[p1]){
                ans++;
                i--;
            }
            p1=(p1+1)%3;    
        }

        if(p1==1){
            ans+=2;
        }
        else if(p1==2){
            ans+=1;
        }

        return ans;    

    }
};