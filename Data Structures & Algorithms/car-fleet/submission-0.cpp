class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int res = 0; double cur = 0;
        priority_queue<pair<int, int>> q;
	    for (int i = 0; i < position.size(); ++i) {
	        q.push({position[i], speed[i]});
	    }   
	    while (!q.empty()) {
	    	auto t = q.top(); q.pop();
            double timeNeeded = (double)(target - t.first) / t.second;
	    	if (timeNeeded <= cur) continue;
	    	cur = timeNeeded;
	    	++res;
	    }
	    return res;
    }
};
