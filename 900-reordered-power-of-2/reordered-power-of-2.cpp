class Solution {
    static unordered_set<string> s;
public:
    string generate(int num){
        vector<int> f(10);
        while(num){
            int d=num%10;
            f[d]++;
            num/=10;
        }

        string str="";

        for(int i=0;i<10;i++){
            str+=f[i];
        }

        return str;

    }

    void process(){
        if(s.size()!=0) return ;
        for(int i=1;i<=1e9;i<<=1){
            string str=generate(i);
            s.insert(str);
        }
    }
    bool reorderedPowerOf2(int n) {
        process();
        return s.find(generate(n))!=s.end();
    }
};

unordered_set<string> Solution::s;