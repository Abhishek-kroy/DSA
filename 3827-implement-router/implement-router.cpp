#include <bits/stdc++.h>
using namespace std;

struct Packet {
    int source, destination, timestamp;
    
    bool operator==(const Packet &other) const {
        return source == other.source &&
               destination == other.destination &&
               timestamp == other.timestamp;
    }
};

struct PacketHash {
    size_t operator()(const Packet &p) const {
        return hash<int>()(p.source) ^ (hash<int>()(p.destination) << 1) ^ (hash<int>()(p.timestamp) << 2);
    }
};

class Router {
    int memoryLimit;
    queue<Packet> q;
    unordered_set<Packet, PacketHash> dupCheck;
    unordered_map<int, vector<int>> timestampMap;
    unordered_map<int, int> offset;

public:
    Router(int limit) : memoryLimit(limit) {}

    bool addPacket(int source, int destination, int timestamp) {
        Packet pkt{source, destination, timestamp};
        if (dupCheck.count(pkt)) return false;

        if ((int)q.size() >= memoryLimit) {
            Packet old = q.front(); q.pop();
            dupCheck.erase(old);
            offset[old.destination]++;
        }

        q.push(pkt);
        dupCheck.insert(pkt);
        timestampMap[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};

        Packet pkt = q.front(); q.pop();
        dupCheck.erase(pkt);
        offset[pkt.destination]++;
        return {pkt.source, pkt.destination, pkt.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto &v = timestampMap[destination];
        int startIdx = offset[destination];

        auto lo = lower_bound(v.begin() + startIdx, v.end(), startTime);
        auto hi = upper_bound(v.begin() + startIdx, v.end(), endTime);

        return (int)(hi - lo);
    }
};