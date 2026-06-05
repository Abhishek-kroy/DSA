class node{
    public:
        vector<node*> ch;
        bool isend;

        node(){
            ch.assign(26,NULL);
            isend=false; 
        }
};

class Trie {
public:
    node* root;    
    Trie() {
        root = new node();    
    }
    
    void insert(string word) {
        node* tmp=root;

        for(auto c:word){
            if(!tmp->ch[c-'a']){
                tmp->ch[c-'a']=new node();
            }

            tmp=tmp->ch[c-'a'];
        }

        tmp->isend=true; 
    }
    
    bool search(string word) {
        node* tmp=root;

        for(auto c:word){
            if(!tmp->ch[c-'a']){
                return false;
            }

            tmp=tmp->ch[c-'a'];
        }

        return tmp->isend; 
    }
    
    bool startsWith(string prefix) {

        node* tmp=root;    

        for(auto c:prefix){        
            if(!tmp->ch[c-'a']){
                return false;
            }

            tmp=tmp->ch[c-'a'];
        }

        return true;      
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */