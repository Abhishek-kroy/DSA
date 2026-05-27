class node{
    public:
        vector<node*> ch;

        node(){
            ch.resize(2);
            ch[0]=NULL;
            ch[1]=NULL;
        }
};

class Trie{
    public :
        node* root=new node();    

        void insert(int num){
            node* tmp=root; 
            for(int i=31;i>=0;i--){
                int b=num&(1<<i);
                if(b){
                    if(tmp->ch[1]!=NULL){
                        tmp=tmp->ch[1];
                    }
                    else{
                        tmp->ch[1]=new node();
                        tmp=tmp->ch[1];
                    }
                }
                else{
                    if(tmp->ch[0]!=NULL){
                        tmp=tmp->ch[0];
                    }
                    else{
                        tmp->ch[0]=new node();
                        tmp=tmp->ch[0];
                    }

                }
            }
        }

        int get(int num){
            node* tmp=root;

            int r=0;

            for(int i=31;i>=0;i--){    
                int b=num&(1<<i);

                if(b){
                    if(tmp->ch[0]!=NULL){
                        tmp=tmp->ch[0];
                    }                                                                 
                    else{
                        r=r|(1<<i);
                        tmp=tmp->ch[1];
                    }
                }
                else{
                    if(tmp->ch[1]!=NULL){
                        r=r|(1<<i);
                        tmp=tmp->ch[1];
                    }                                                                 
                    else{
                        tmp=tmp->ch[0];
                    }
                }
            }            

            return num^r; 
        }

};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();

        // vector<int> res(n);

        int res=0;

        Trie* t=new Trie();

        for(int i=0;i<n;i++){
            t->insert(nums[i]);        
        }

        for(int i=0;i<n;i++){
            res=max(res,t->get(nums[i]));     
        }

        return res;


        
    }
};