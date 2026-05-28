class node{
public:

    node* ch[26];
    int ind;

    node(){

        ind=-1;

        for(int i=0;i<26;i++){
            ch[i]=NULL;
        }
    }
};

class trie{
public:

    node* root=new node();

    vector<string>& words;

    int mx;

    trie(vector<string>& words,int mx):words(words),mx(mx){}

    void insert(string& word,int i){

        node* tmp=root;

        if(tmp->ind==-1){
            tmp->ind=i;
        }
        else if(words[i].size()==words[tmp->ind].size()){
            tmp->ind=min(i,tmp->ind);
        }
        else if(words[i].size()<words[tmp->ind].size()){
            tmp->ind=i;
        }

        for(int j=word.size()-1,cnt=0;j>=0 && cnt<mx;j--,cnt++){

            char c=word[j];

            if(tmp->ch[c-'a']==NULL){
                tmp->ch[c-'a']=new node();
            }

            tmp=tmp->ch[c-'a'];

            if(tmp->ind==-1){
                tmp->ind=i;
            }
            else if(words[i].size()==words[tmp->ind].size()){
                tmp->ind=min(i,tmp->ind);
            }
            else if(words[i].size()<words[tmp->ind].size()){
                tmp->ind=i;
            }
        }
    }

    int get(string& suf){

        node* tmp=root;

        int ans=-1;

        for(int j=suf.size()-1;j>=0;j--){

            char c=suf[j];

            if(tmp->ch[c-'a']!=NULL){
                tmp=tmp->ch[c-'a'];
            }
            else{
                ans=tmp->ind;
                break;
            }
        }

        if(ans==-1){
            ans=tmp->ind;
        }

        return ans;
    }
};

class Solution {
public:

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {

        int mx=0;

        for(auto& s:wordsQuery){
            mx=max(mx,(int)s.size());
        }

        trie* t=new trie(wordsContainer,mx);

        for(int i=0;i<wordsContainer.size();i++){
            t->insert(wordsContainer[i],i);
        }

        int m=wordsQuery.size();

        vector<int> ans(m);

        for(int i=0;i<m;i++){
            ans[i]=t->get(wordsQuery[i]);
        }

        return ans;
    }
};    