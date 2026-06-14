class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1e9, mid = 0, cnt = 0;
        while (left < right) {
            mid = left + (right - left) / 2; // get the current speed
            cnt = 0;
            for (int pile : piles) cnt += (pile + mid - 1) / mid; // use the ceilling function to get the required 
            if (cnt > h) left = mid + 1; // currernt speed is too slow, increase left border to high-speed interval
            else right = mid; // current speed is fast enough, decrease right bnorder for low-speed interval
        }
        return right;
    }
};
