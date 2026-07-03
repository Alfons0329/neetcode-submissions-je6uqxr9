class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n);
        return nums;
    }
private:
    void mergeSort(vector<int>& arr, int L, int R) {
        // outp of boundary, the ! of while(L < R)
        // note not. (L  >= R) brcause 1 element also not need to sort
        if (L + 1>= R) {
            return;
        }

        // similar to m in the binary search
        // L inclusive R exclusive
        int M = L + (R - L) / 2;
        mergeSort(arr, L, M);
        mergeSort(arr, M, R) ;
        merge(arr, L, M, R);
    }

    // write a merge sort from scratch
    
    void merge(vector<int>& arr, int L, int M, int R) {
        vector<int> mergedArray;

        // merge 2 portion of array together
        int arrIdx1 = L, arrIdx2 = M;
        // [L..(arrIdx1)..M..(arrIdx2)..R]

        while(arrIdx1 < M && arrIdx2 < R) {
            if (arr[arrIdx1] < arr[arrIdx2]) {
                mergedArray.push_back(arr[arrIdx1++]);
            } else {
                mergedArray.push_back(arr[arrIdx2++]);
            }
        }


        // assume left is smaller
        while (arrIdx1 < M) {
            mergedArray.push_back(arr[arrIdx1++]);
        }
        while (arrIdx2 < R) {
            mergedArray.push_back(arr[arrIdx2++]);
        }


        // assign back to the oriignal array
        for (int mergedIdx = 0; mergedIdx < mergedArray.size(); mergedIdx++) {
            arr[L + mergedIdx] = mergedArray[mergedIdx];
        }
    }
};