class node{
    public:
        vector<node*> ch;
        bool isend;

        node(){
            ch.assign(26,NULL);            

            isend=false; 
        }
};

class trie{
    public:
        node* root= new node();

        int insert(string& str){
            node* tmp=root;

            int len=0; 

            bool s=true; 

            for(auto c:str){
                if(tmp->ch[c-'a']==NULL){
                    s=false;
                    tmp->ch[c-'a']=new node();
                }

                if(s){
                    len++; 
                }

                tmp=tmp->ch[c-'a'];
            }

            return len; 
        }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int ans=INT_MAX; 

        trie* t=new trie();

        t->insert(strs[0]);

        for(auto str:strs){
            ans=min(ans,t->insert(str));
        }

        return strs[0].substr(0,ans);            

    }
};