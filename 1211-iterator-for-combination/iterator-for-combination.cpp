class CombinationIterator {
    vector<int> bit;
    string str; 
    int len; 
    int k; 
    bool set;
public:
    CombinationIterator(string characters, int combinationLength) {
        str=characters;
        len=str.size();
        bit.resize(len);
        k=combinationLength; 
        set=false;
        for(int i=0;i<len;i++){
            if(i<k){
                bit[i]=1;
            }
            else{
                bit[i]=0; 
            }
        }
    }
    
    string next() {
        string ans="";
        for(int i=0;i<len;i++){
            if(bit[i]){
                ans+=str[i];
            }
        }

        int j=len-1;
        int cnt=0;
        while(j>=0 && bit[j]){ 
            cnt++;
            j--;
        }

        int last=-1; 
        for(int i=j;i>=0;i--){ 
            if(bit[i]==1){ 
                last=i;
                break;
            }
        } 

        if (last == -1) { 
            set=true;
            return ans;
        }

        j=last;
        bit[j]=0;
        j++; 
        bit[j]=1;
        while(cnt--){
            j++;
            bit[j]=1;  
        }
        while(j+1<len){
            j++;              
            bit[j]=0;  
        } 

        return ans;

    }
    
    bool hasNext() {
        if(set) return false; 
        int j=len-1;
        int cnt=0;
        while(j>=0 && bit[j]){
            cnt++;
            j--;
        }

        if(cnt==k){ 
            set=true;
            return true;
        }

        return true;  
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */