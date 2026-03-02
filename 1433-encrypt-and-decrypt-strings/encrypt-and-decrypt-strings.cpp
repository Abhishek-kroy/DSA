class Node {
public:    
    Node* ch[26];
    bool eow;
    Node() {
        for(int i=0;i<26;i++) ch[i]=NULL;
        eow=false;
    }
};    

class Trie {
public:

    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string &s) {
        Node* cur = root;
        for(char c : s) {
            int id = c - 'a';
            if(!cur->ch[id]) cur->ch[id] = new Node();
            cur = cur->ch[id];
        }
        cur->eow = true;
    }

    bool search(string &s) {
        Node* cur = root;
        for(char c : s) {
            int id = c - 'a';
            if(!cur->ch[id]) return false;
            cur = cur->ch[id];
        }
        return cur->eow;
    }

    bool startsWith(string &s) {
        Node* cur = root;
        for(char c : s) {
            int id = c - 'a';
            if(!cur->ch[id]) return false;
            cur = cur->ch[id];
        }
        return true;
    }
};

class Encrypter {
    unordered_map<char,string> enc;
    unordered_map<string,vector<char>> dec;
    // unordered_set<string> allowed;
    Trie* tree;
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        int n=keys.size();
        for(int i=0;i<n;i++){
            enc[keys[i]]=values[i];
            dec[values[i]].push_back(keys[i]);              
        }

        tree=new Trie();

        for(auto d:dictionary){
            tree->insert(d);
        }
    }
    
    string encrypt(string word1) {

        // if(!tree->search(word1)){    
        //     return "";            
        // }    

        string ans="";
        int n=word1.size();
        for(int i=0;i<n;i++){
            char c=word1[i];
            if(enc.find(c)==enc.end()){
                return "";
            }
            ans+=enc[c];
        }
        return ans;
    }
    
    int decrypt(string word2) {
        int n=word2.size();
        if(n%2){
            return 0;
        }

        vector<Node*> validptr;
        validptr.push_back(tree->root);  

        for(int i=0;i<n;i+=2){
            string c="";
            c += word2[i];
            c += word2[i+1];      
            vector<Node*> nextvalidptr;    

            for(auto val:dec[c]){
                for(auto ptr:validptr){
                    if(ptr->ch[val-'a']){
                        nextvalidptr.push_back(ptr->ch[val-'a']);
                    }
                }
            }

            validptr=nextvalidptr;

        }

        int size=0;

        for(auto ptr:validptr){
            if(ptr->eow){
                size++;
            }
        }

        return size;      
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */