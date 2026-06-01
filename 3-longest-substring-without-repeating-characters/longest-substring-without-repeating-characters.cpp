class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.size();

        int i=0;
        int j=0;

        int ans=0; 

        unordered_set<int> st;

        while(j<n){
            while(st.find(s[j])!=st.end()){
                st.erase(s[i]);
                i++;
            }

            st.insert(s[j]);        

            ans=max(ans,j-i+1);                                            
            j++;  
        }

        return ans; 
    }
};