class Solution {
    static vector<string> s;
    static vector<string> is;
public:
    static void process(){
        if(s.size()){
            return ;
        }

        s.resize(20);
        is.resize(20);

        s[0]="0";
        is[0]="1";  

        // cout<<s[0]<<" "<<is[0]<<endl;    

        for(int i=1;i<20;i++){
            string str=is[i-1];
            string str1=s[i-1];    

            reverse(str.begin(),str.end());
            reverse(str1.begin(),str1.end());    

            s[i]=s[i-1]+"1"+str;
            is[i]=is[i-1]+"0"+str1;    

            // cout<<s[i]<<" "<<is[i]<<endl;    
        }



    }
    char findKthBit(int n, int k) {
        process();

        string str=s[n-1];

        return str[k-1];    
    }


};

vector<string> Solution::s;
vector<string> Solution::is;  