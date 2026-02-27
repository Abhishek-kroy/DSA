class MedianFinder {
    priority_queue<int> lefthalf;
    priority_queue<int,vector<int>,greater<int>> righthalf;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(lefthalf.empty()){
            lefthalf.push(num);
            return ;
        }

        if(lefthalf.top()>=num){
            lefthalf.push(num);
        }
        else{
            righthalf.push(num);
        }

        if(lefthalf.size()>righthalf.size()+1){
            int val=lefthalf.top();
            lefthalf.pop();
            righthalf.push(val);
        }
        else if(lefthalf.size()+1<righthalf.size()){
            int val=righthalf.top();
            righthalf.pop();
            lefthalf.push(val);
        }
    }
    
    double findMedian() {
        if((lefthalf.size()+righthalf.size())%2){
            if(lefthalf.size()>righthalf.size()){
                return lefthalf.top();
            }

            return righthalf.top();
        }

        return (double)(lefthalf.top()+righthalf.top())/(double)2; 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */