/*
Intuition: Binary search
Approach:
    Set: unordered_map<key, map<timestamp, value>>
        key for fast search
        map<timestamp> for strictly increasing (the treeMap)
    Get:
        if kv[key].at(timestamp) !=null, return this
        else find kv[key].at(timestamp) return lower_bound(tiemstamp)

Complexity:
    Time: O(1) for set O(logN) to get and N is actually the timestamp
    Space: up to (time x value)

*/
class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        kv[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (kv[key].find(timestamp) != kv[key].end()) {
            return kv[key][timestamp];
        }
        // find the closest previous one
        auto it = kv[key].upper_bound(timestamp);
        // be sure to get back to the previous element since upper_bound search for the first >, 
        // then the previous will definiltely be <=
        if (it == kv[key].begin()) {
            // not inserted yet, reutrn empty
            return "";
        }
        // return the previous one
        --it;
        return it->second;
    }
private:
    unordered_map<string, map<int, string>> kv;
};
