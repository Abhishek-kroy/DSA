class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<int,int> l;
        int n=s.size();

        for(int i=0;i<n;i++){
            l[s[i]-'a']=i;
        }

        unordered_set<char> used;     

        stack<char> st;
        int i=0;
        for(auto c:s){
            if(used.find(c)!=used.end()) {
                i++; 
                continue;
            }
            if(st.empty() || st.top()<c){  
                st.push(c);  
                used.insert(c);
            }
            else{
                while(!st.empty() && st.top()>c && l[st.top()-'a']>i){           
                    used.erase(st.top());
                    st.pop();
                }  
                st.push(c);  
                used.insert(c);    
            }
                i++;
        }

        string ans;
        ans.reserve(st.size());
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end()); 

        return ans;
    }
};