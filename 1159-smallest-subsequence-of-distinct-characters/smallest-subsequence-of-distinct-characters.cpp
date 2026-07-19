class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int> ind;

        for(int i=0;i<s.size();i++){
            ind[s[i]]=i;    
        }          

        stack<char> st;    

        vector<bool> vis(26,false);  

        for(int i=0;i<s.size();i++){    
            char c=s[i];

            if(vis[c-'a'])
    continue;

            while(!st.empty() &&  st.top() > c && ind[st.top()]>i){      
                vis[st.top()-'a']=false;    
                st.pop();
            }
            st.push(c);          
            vis[c-'a']=true;
        }  

        string ans="";

        while(!st.empty()){
            ans = string(1, st.top()) + ans;       

            st.pop();
        }    

        return ans; 
    }
};