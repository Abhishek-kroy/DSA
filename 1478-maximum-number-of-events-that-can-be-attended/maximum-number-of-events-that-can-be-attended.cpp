#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
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

        // Sort events
        sort(events.begin(), events.end());

        // // Debug: Print sorted events
        // cout << "\nSorted events:\n";
        // for (const auto& e : events) {
        //     cout << "[" << e[0] << ", " << e[1] << "]\n";
        // }

        unordered_set<int> attendedDays;
        int cnt = 0;
        int i = 0, n = events.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int d = 1; d <= 100000; d++) {
            // Remove expired events
            while (!pq.empty() && pq.top() < d) {
                // cout << "Removing expired event ending on day " << pq.top() << "\n";
                pq.pop();
            }

            // Add new events starting today
            while (i < n && events[i][0] <= d) {
                pq.push(events[i][1]);
                // cout << "Adding event [" << events[i][0] << ", " << events[i][1] << "] to PQ\n";
                i++;
            }

            // Attend an event if available
            if (!pq.empty() && pq.top() >= d) {
                // cout << "Attending event ending on day " << pq.top() << " on day " << d << "\n";
                cnt++;
                pq.pop();
            }

            // Stop early if no events are left
            if (pq.empty() && i >= n) break;
        }

        // Debug: Print total attended events
        // cout << "\nTotal events attended: " << cnt << "\n";

        return cnt;
    }
};