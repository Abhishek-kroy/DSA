class node {
public:
    vector<node*> children;
    bool isend;  
    node(){
        children.assign(26,NULL);
        isend=false;
    }
};

class Trie {
    node* root;
public:
    Trie() {
        root=new node();
    }
    
    void insert(string word) {
        node* temp=root;
        for(auto c:word){
            int ind=c-'a';
            if(temp->children[ind]==NULL){
                temp->children[ind]=new node();
            }
            temp=temp->children[ind];  
        }

        temp->isend=true; 
    }
    
    bool search(string word) {
        node* temp=root;
        for(auto c:word){
            int ind=c-'a';
            if(temp->children[ind]==NULL){
                return false;
            }
            temp=temp->children[ind];  
        }

        return temp->isend;
    }
    
    bool startsWith(string prefix) {
        node* temp=root;
        for(auto c:prefix){      
            int ind=c-'a';
            if(temp->children[ind]==NULL){
                return false;
            }
            temp=temp->children[ind];        
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