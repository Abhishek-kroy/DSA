unordered_map<char,int> freq;

class cmp{
    public:
        bool operator()(char a,char b){
            if(freq[a]==freq[b]){
                return a<b;
            }

            return freq[a]>freq[b];
        }
};

class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;

        freq.clear();      

        for(auto c:word){
            freq[c]++;
        }

        sort(word.begin(),word.end(),cmp());


        // cout<<word<<endl;



        unordered_map<char,int> f;
        int cnt=0;
        int loop=0;

        for(auto c:word){
            if(f.find(c)!=f.end()){
                ans+=f[c];
            }
            else{
                cnt=(cnt)%8;

                if(cnt==0){
                    loop++;
                }

                f[c]=loop;
                ans+=f[c];

                cnt=(cnt+1)%8;
            }
        }

        return ans; 
    }
};