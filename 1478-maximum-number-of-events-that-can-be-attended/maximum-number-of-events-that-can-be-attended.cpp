#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Debug: Print unsorted events
        // cout << "Unsorted events:\n";
        // for (const auto& e : events) {
        //     cout << "[" << e[0] << ", " << e[1] << "]\n";
        // }

        // Corrected sorting logic: Sort by end time, then by start time
        // sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
        //     if (a[1] != b[1]) return a[1] < b[1]; // Sort by end time first
        //     return a[0] < b[0];  // If same end time, sort by start time
        // });

        // Debug: Print sorted events
        // cout << "\nSorted events:\n";
        // for (const auto& e : events) {
        //     cout << "[" << e[0] << ", " << e[1] << "]\n";
        // }

        sort(events.begin(),events.end());
        unordered_set<int> attendedDays;
        int cnt = 0;

        int i=0;
        int n=events.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int d=1;d<=100000;d++){
            while(!pq.empty() and pq.top()<d) pq.pop();
            while(i<n and events[i][0]==d){
                pq.push(events[i][1]);
                i++;
            }
            if (!pq.empty()) {
                cnt++;
                pq.pop();
            }
        }

        return cnt;

        // Debug: Print final count of attended events
        cout << "\nTotal events attended: " << cnt << "\n";

        return cnt;
    }
};