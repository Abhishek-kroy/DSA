class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n=encodedText.size();

        int col=n/rows;

        string ans="";

        for(int j=0;j<col;j++){
            int i=j;
            string sub="";
            while(i<n){
                sub+=encodedText[i];
                i=i+col+1;
            }

            ans+=sub;   

        }

        int j=ans.size();
        while(j-1>=0 && ans[j-1]==' '){
            j--;
        }

        string res="";

        for(int i=0;i<j;i++){
            res+=ans[i];
        }

        return res; 
    }
};