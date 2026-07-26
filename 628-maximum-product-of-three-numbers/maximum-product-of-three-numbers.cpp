class Solution {
public:
    void insertneg(vector<int>& neg,int v){
        for(int i=0;i<3;i++){
            if(neg[i]>v){
                for(int j=2;j>i;j--){
                    neg[j]=neg[j-1];
                }

                neg[i]=v;

                break;
            }
        }
    }

    void insertpos(vector<int>& pos,int v){
        for(int i=0;i<3;i++){
            if(pos[i]<v){
                for(int j=2;j>i;j--){
                    pos[j]=pos[j-1];
                }

                pos[i]=v;

                break;
            }
        }
    }

    int maximumProduct(vector<int>& nums) {
        vector<int> neg(3,INT_MAX);
        vector<int> pos(3,INT_MIN);

        for(auto v:nums){
            insertneg(neg,v);
            insertpos(pos,v);
        }

        cout<<neg[0]<<" "<<neg[1]<<" "<<pos[0]<<" "<<neg[0]*neg[1]*pos[0]<<endl;
        cout<<pos[0]<<" "<<pos[1]<<" "<<pos[2]<<" "<<pos[0]*pos[1]*pos[2]<<endl;

        return max({neg[0]*neg[1]*pos[0],pos[0]*pos[1]*pos[2]});
    }
};