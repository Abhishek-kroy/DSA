class Solution {
public:
    bool getans(vector<int>& rec1, vector<int>& rec2){
        int t1=rec1[3];
        int b1=rec1[1];

        int t2=rec2[3];
        int b2=rec2[1];
        
        int r1=rec1[2];
        int l1=rec1[0];

        int r2=rec2[2];
        int l2=rec2[0];

        cout<<"t1 and t2 "<<t1<<" "<<t2<<endl;
        cout<<"b1 and b2 "<<b1<<" "<<b2<<endl;

        if((t1>=t2 && b1<=t2) || (t1>=b2 && b1<=b2)){
            cout<<"entered"<<endl;
            if(r2<=l1 || l2>=r1){
                return false;
            }

            return true;
        }
        return false;
    }
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int t1=rec1[3];
        int b1=rec1[1];

        int t2=rec2[3];
        int b2=rec2[1];
        
        int r1=rec1[2];
        int l1=rec1[0];

        int r2=rec2[2];
        int l2=rec2[0];

        cout<<"t1 and t2 "<<t1<<" "<<t2<<endl;
        cout<<"b1 and b2 "<<b1<<" "<<b2<<endl;

        if((t1>=t2 && b1<=t2) || (t1>=b2 && b1<=b2)){
            cout<<"entered"<<endl;
            if(!(r2<=l1 || l2>=r1)){
                return true;
            }

        }

        return getans(rec2,rec1);
    }
};