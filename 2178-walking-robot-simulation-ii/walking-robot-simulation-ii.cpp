class Robot {
    string dir;
    int x;
    int y;
    int i;
    int j;
public:
    Robot(int width, int height) {
        x=width-1;
        y=height-1;
        i=0;
        j=0;
        dir="East";
    }
    
    void step(int num) {
        num=num%(2*(x)+2*(y));    
        if(num==0){
            if(i==0 && j==0){
                dir="South";
            }
            return ;
        }

        if(dir=="East"){
            int cur=i;
            if(x-cur<num){
                dir="North";
                i=x;
                this->step(num-(x-cur));
            }
            else{
                i+=num;
            }
        }
        else if(dir=="West"){
            int cur=i;
            if(cur<num){
                dir="South";
                i=0;
                this->step(num-(cur));
            }
            else{
                i-=num;
            }
        }
        else if(dir=="North"){
            int cur=j;
            if(y-cur<num){
                dir="West";
                j=y;
                this->step(num-(y-cur));
            }
            else{
                j+=num;
            }
        }
        else{
            int cur=j;
            if(cur<num){
                dir="East";
                j=0;   
                this->step(num-(cur));   
            }
            else{
                j-=num;
            }
        }
    }
    
    vector<int> getPos() {
        return {i,j};
    }
    
    string getDir() {
        return dir;   
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */