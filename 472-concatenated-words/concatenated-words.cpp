class Node {
    public:
        Node* ch[26];
        bool isend;
        Node(){
            for(int i=0;i<26;i++){
                ch[i]=NULL;
            }    
            isend=false;
        }
};

class Trie {
    public:
        Node* root;
        Trie(){
            root =new Node();
        }

        void insert(string word){
            Node* temp=root;
            int n=word.size();
            for(int i=0;i<n;i++){
                int c=word[i]-'a';
                if(temp->ch[c]!=NULL){
                    temp=temp->ch[c];
                }
                else{
                    temp->ch[c]=new Node();
                    temp=temp->ch[c];
                }
            }
            temp->isend=true;
        }

        bool query(string& word,Node* start,int i,vector<int>& dp){
            int n=word.size();
            if(i>=n){
                return true;
            }
            if(!start){
                return false;
            }

            if(dp[i]!=-1){
                return dp[i];
            }

            Node* temp=start;  

            int ind=i;  

            bool ans=false;

            while(i<n && !ans){
                int c=word[i]-'a';
                if(temp->ch[c]==NULL){
                    break;    
                }
                temp=temp->ch[c];
                if(temp->isend){
                    ans=query(word,root,i+1,dp);    
                }    
                i++;
            }

            dp[ind]=ans;    

            return ans;    
        }

};

class Solution {
public:
    struct cmp{

        bool operator()(string& a,string& b){
            return a.size()<b.size();
        }                                                        
    };

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(),words.end(),cmp());

        Trie* t=new Trie();

        int n=words.size();

        vector<string> ans;
        vector<int> dp;    

        for(int i=0;i<n;i++){

            dp.assign(words[i].size(),-1);    
            if(t->query(words[i],t->root,0,dp)){
                ans.push_back(words[i]);
            }                           

            t->insert(words[i]);    
        }

        return ans;     
    }
};