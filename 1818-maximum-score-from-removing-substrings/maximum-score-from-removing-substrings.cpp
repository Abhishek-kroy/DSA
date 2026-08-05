class Solution {
public:
    string removeab(string s,int& v,int val){
        int n=s.size();
        stack<char> st;

        for(int i=0;i<n;i++){
            if(st.empty() || s[i]!='b'){
                st.push(s[i]);
            }
            else if(st.top()=='a'){
                v+=val;
                st.pop();                                
            }
            else{
                st.push(s[i]);
            }
        }

        string str="";
        while(!st.empty()){
            auto c=st.top();
            st.pop();

            str+=c;
        }
        reverse(str.begin(),str.end());


        return str;
    }
    string removeba(string s,int& v,int val){
        int n=s.size();
        stack<char> st;

        for(int i=0;i<n;i++){
            if(st.empty() || s[i]!='a'){
                st.push(s[i]);
            }
            else if(st.top()=='b'){
                v+=val;
                st.pop();                                
            }
            else{
                st.push(s[i]);
            }
        }

        string str="";
        while(!st.empty()){
            auto c=st.top();
            st.pop();

            str+=c;
        }
        reverse(str.begin(),str.end());


        return str;
    }
    int maximumGain(string s, int x, int y) {
        int ans=0;

        if(x>=y){
            string temp=removeab(s,ans,x);
            string t2=removeba(temp,ans,y);

            return ans;
        }

        string t2=removeba(s,ans,y);    
        string temp=removeab(t2,ans,x);
        return ans;
    }
};