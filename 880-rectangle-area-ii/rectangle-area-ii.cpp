#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    int n; 
    vector<vector<pair<long long,long long>>> seg;

    SegmentTree(int n){
        this->n = n;
        seg.resize(4 * n);
    }

    void rangeupdate(int ind, int left, int right,
                     int ql, int qr,
                     long long lx, long long rx){

        if(right < ql || left > qr) return;

        if(left == right){
            seg[ind].push_back({lx, rx});
            return;
        }

        int mid = (left + right) / 2;
        rangeupdate(2*ind+1, left, mid, ql, qr, lx, rx);
        rangeupdate(2*ind+2, mid+1, right, ql, qr, lx, rx);
    }

    void update(int yl, int yr, long long lx, long long rx){
        if(yl <= yr)
            rangeupdate(0, 0, n-1, yl, yr, lx, rx);
    }

    long long mergedLength(int idx){
        int ind = 0, left = 0, right = n-1;
        while(left != right){
            int mid = (left + right) / 2;
            if(idx <= mid){
                ind = 2*ind + 1;
                right = mid;
            } else {
                ind = 2*ind + 2;
                left = mid + 1;
            }
        }

        auto &v = seg[ind];
        if(v.empty()) return 0;

        sort(v.begin(), v.end());

        long long ans = 0;
        long long start = v[0].first, end = v[0].second;

        for(int i = 1; i < (int)v.size(); i++){
            if(v[i].first > end){
                ans += end - start;
                start = v[i].first;
                end = v[i].second;
            } else {
                end = max(end, v[i].second);
            }
        }

        ans += end - start;
        return ans;
    }
};

class Solution {
public:
    long long rectangleArea(vector<vector<int>>& rectangles) {

        int MOD = 1e9 + 7;

        vector<long long> ys;
        for(auto &r : rectangles){
            ys.push_back(r[1]);
            ys.push_back(r[3]);
        }

        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        unordered_map<long long,int> yid;
        for(int i = 0; i < (int)ys.size(); i++)
            yid[ys[i]] = i;

        SegmentTree st((int)ys.size() - 1);

        for(auto &r : rectangles){
            int yl = yid[r[1]];
            int yr = yid[r[3]] - 1;
            st.update(yl, yr, r[0], r[2]);
        }

        long long ans = 0;
        for(int i = 0; i < (int)ys.size() - 1; i++){
            long long height = ys[i+1] - ys[i];
            long long coveredX = st.mergedLength(i);
            ans = (ans + (height * coveredX) % MOD) % MOD;
        }

        return ans;
    }
};  