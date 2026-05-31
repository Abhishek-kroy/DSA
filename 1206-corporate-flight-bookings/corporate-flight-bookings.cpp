class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> flight(n+2,0);

        for(auto booking:bookings){
            int f=booking[0];
            int l=booking[1];
            int s=booking[2];

            flight[f]+=s;
            flight[l+1]-=s;
        }

        vector<int> ans(n); 

        for(int i=1;i<=n;i++){
            flight[i]+=flight[i-1];

            ans[i-1]=flight[i];                        
        }

        return ans; 
    }
};