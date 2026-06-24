class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), l = 0;
        vector<int> res(n - k + 1);
        deque<int> q;  // stores INDICES, not values

        for (int r = 0; r < n; r++) {
            // Remove smaller candidates from back
            while (!q.empty() && nums[q.back()] < nums[r]) {
                q.pop_back();
            }
            q.push_back(r);  // add current index

            // Remove expired indices from front
            if (l > q.front()) {
                q.pop_front();
            }

            // Record result when window is full
            if (r - l + 1 == k) {
                res[l] = nums[q.front()];  // front always has max
                l++;
            }
        }

        return res;
    }
};