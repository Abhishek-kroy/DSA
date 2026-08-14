class bit {
public:
    vector<long long> f;
    int n;

    bit(int _n) {
        n = _n + 1;
        f.resize(n, 0);
    }

    void update(int i, long long val) {
        i++;

        while(i < n) {
            f[i] += val;
            i += (i & -i);
        }
    }

    long long queries(int ind) {
        if(ind < 0)
            return 0;

        ind++;

        long long ans = 0;

        while(ind > 0) {
            ans += f[ind];
            ind -= (ind & -ind);
        }

        return ans;
    }
};


class Solution {
public:

    bool ispeak(vector<int>& nums, int i) {
        int n = nums.size();

        return i > 0 &&
               i < n-1 &&
               nums[i] > nums[i-1] &&
               nums[i] > nums[i+1];
    }


    void addPeak(
        int p,
        set<int>& peaks,
        bit* f0,
        bit* f1
    ) {
        
        auto it = peaks.lower_bound(p);

        int nxt = (it == peaks.end() ? -1 : *it);
        int prv = -1;

        if(it != peaks.begin()) {
            auto temp = it;
            --temp;
            prv = *temp;
        }

      
        int prev = (prv == -1 ? 0 : prv);

        long long delta = p - prev;

        f0->update(p, delta);
        f1->update(p, 1LL * p * delta);

        if(nxt != -1) {
            long long oldPrev = (prv == -1 ? 0 : prv);
            long long oldDelta = nxt - oldPrev;

            long long newDelta = nxt - p;

            f0->update(nxt, newDelta - oldDelta);
            f1->update(
                nxt,
                1LL * nxt * (newDelta - oldDelta)
            );
        }

        peaks.insert(p);
    }


    void removePeak(
        int p,
        set<int>& peaks,
        bit* f0,
        bit* f1
    ) {
        auto it = peaks.find(p);

        if(it == peaks.end())
            return;

        int prv = -1;
        int nxt = -1;

        if(it != peaks.begin()) {
            auto temp = it;
            --temp;
            prv = *temp;
        }

        auto temp = it;
        ++temp;

        if(temp != peaks.end())
            nxt = *temp;

        int prev = (prv == -1 ? 0 : prv);

        
        long long delta = p - prev;

        f0->update(p, -delta);
        f1->update(p, -1LL * p * delta);

        
        if(nxt != -1) {
            long long oldDelta = nxt - p;
            long long newDelta = nxt - prev;

            f0->update(nxt, newDelta - oldDelta);
            f1->update(
                nxt,
                1LL * nxt * (newDelta - oldDelta)
            );
        }

        peaks.erase(it);
    }


    vector<long long> countOfPeaks(
        vector<int>& nums,
        vector<vector<int>>& queries
    ) {
        int n = nums.size();

        bit* f0 = new bit(n);
        bit* f1 = new bit(n);

        set<int> peaks;

        
        for(int i = 1; i < n-1; i++) {
            if(ispeak(nums, i)) {
                addPeak(i, peaks, f0, f1);
            }
        }

        vector<long long> ans;

        for(auto q : queries) {

            int type = q[0];
            int l = q[1];
            int r = q[2];

            if(type == 1) {

                auto it = peaks.lower_bound(l + 1);

                if(it == peaks.end() || *it >= r) {
                    ans.push_back(0);
                    continue;
                }

                int first = *it;

                long long res =
                    1LL * (first-l) * (r-first);

                auto it2 = it;
                ++it2;

                if(it2 != peaks.end() && *it2 < r) {

                    int last = r-1;

                    long long sumDelta =
                        f0->queries(last) -
                        f0->queries(first);

                    long long sumValue =
                        f1->queries(last) -
                        f1->queries(first);

                    res +=
                        1LL * r * sumDelta -
                        sumValue;
                }

                ans.push_back(res);
            }

            else {

                int idx = l;
                int val = r;

                vector<int> affected = {
                    idx-1,
                    idx,
                    idx+1
                };

                for(int x : affected) {
                    if(ispeak(nums, x)) {
                        removePeak(x, peaks, f0, f1);
                    }
                }

                nums[idx] = val;

                for(int x : affected) {
                    if(ispeak(nums, x)) {
                        addPeak(x, peaks, f0, f1);
                    }
                }
            }
        }

        return ans;
    }
};