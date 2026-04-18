/*
Intution: Use hash_map to count the freq and then priority_queue() to get top K 

Approach: 
    1. Create nums -> freq map
    2. Priority queue sort by freq
    3. Get top k freq


Complexty:
    Time:   O(DlogD), where D is count of distinct elements in nums, hen
    Space:  O(D), where D is count of distinct elements in nums, hen
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, unsigned int> freq; //map nums->freq
        for (int &num : nums ) {
            freq[num]++;
        }

        priority_queue<pair<int, unsigned int>> pq;
        for (auto const& [val, freq] : freq) {
            pq.push({freq, val}); // max-heap by default
        }

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
