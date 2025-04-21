class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        unordered_set<int> s;
        int i=0;
        int n=instructions.size();
        long long score=0;
        while(i>=0 and i<n and s.find(i)==s.end()){
            s.insert(i);
            if(instructions[i]=="add"){
                score+=values[i];
                i++;
            }
            else{
                i+=values[i];
            }
        }

        return score;
    }
};