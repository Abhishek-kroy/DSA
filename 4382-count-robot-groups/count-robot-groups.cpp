class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
         int n = position.size();

        int groups = 1;

        int groupSpeed = speed[n - 1];

        for (int i = n - 2; i >= 0; i--) {

            if (position[i+1] - position[i] <= distance ||
                speed[i] > groupSpeed) {
                
                continue;
            }

            groups++; 
            groupSpeed = speed[i];            
        }

        return groups;
    }
};