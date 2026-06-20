class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        if (n > m) return findMedianSortedArrays(b, a);

        // aray to satisfies
        /*
            a[] // smaller array, a
            b[] // bigger array b
            LA mid1 LB RA mid2 RB

            ensure LA <= RB and LB <= RA 
        */

        // ensure n smaller then m
        int low = 0, high = n;
        while(low <= high) {
            int mid1 = (low + high) / 2;        // find the partition for smaller array
            int mid2 = (n + m + 1) / 2 - mid1;  // find the partition for larger array

            // find elements to the left and right of partition in smaller array
            int la = (mid1 == 0 ? INT_MIN : a[mid1 - 1]);   // LA, if LA empty, make it as small as possible to ditch it directly
            int ra = (mid1 == n ? INT_MAX : a[mid1]);       // RB, if RB empty, make it as big as possible to ditch it directly

            // find elements to the left and right of 
            int lb = (mid2 == 0 ? INT_MIN : b[mid2 - 1]);   // LB, logic same as above
            int rb = (mid2 == m ? INT_MAX : b[mid2]);       // RB, logic same as above

            // if it is a valid partition
            if (la <= rb && lb <= ra) {
          
          	    // if the total elements are even, then median is 
          	    // the average of two middle elements
                if ((n + m) % 2 == 0)
                    return (max(la, lb) + min(ra, rb)) / 2.0;
          
          	    // if the total elements are odd, then median is 
         	    // the middle element
                else
                    return max(la, lb);
            }

            // check if we need to take lesser elements from a[]
            if (la > rb){
                high = mid1 - 1;
            }
            // check if we need to take more elements from a[]
            else{
                low = mid1 + 1;
            }
        }

        return 0;
    }
};
