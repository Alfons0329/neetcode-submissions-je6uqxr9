class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        if (n > m) return findMedianSortedArrays(b, a);

        int low = 0, high = n;
        int half_len = (n + m + 1) / 2;

        while (low < high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = half_len - mid1;

            int lb = (mid2 == 0 ? INT_MIN : b[mid2 - 1]);
            int ra = (mid1 == n ? INT_MAX : a[mid1]);

            if (lb <= ra) {
                high = mid1;
            } else {
                low = mid1 + 1;
            }
        }

        int mid1 = low;
        int mid2 = half_len - mid1;

        int la = (mid1 == 0 ? INT_MIN : a[mid1 - 1]);
        int ra = (mid1 == n ? INT_MAX : a[mid1]);
        int lb = (mid2 == 0 ? INT_MIN : b[mid2 - 1]);
        int rb = (mid2 == m ? INT_MAX : b[mid2]);

        if ((n + m) % 2 == 0) {
            return (max(la, lb) + min(ra, rb)) / 2.0;
        } else {
            return max(la, lb);
        }
    }
};