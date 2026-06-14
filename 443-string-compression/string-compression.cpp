class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();

        int i=0;

        int k=0;

        while(i<n){
            int j=i;
            int cnt=0;
            while(j<n&& chars[j]==chars[i]){
                j++;       
                cnt++;
            }



            chars[k]=chars[i];
            k++;

            if(cnt!=1){
                string cnt2=to_string(cnt);
                for(auto l:cnt2){
                    chars[k]=l;
                    k++;                                         
                }
            }

            i=j; 
        }

        return k; 
    }
};