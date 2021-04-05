class Solution {
public:
    int merge(vector<int>& A, vector<int>& temp, int left, int mid, int right) {
        int i = left;
        int j = mid+1;
        int k = left;
        int count = 0;
        
        while (i <= mid && j <= right) {
            if (A[i] <= A[j]) {
                temp[k++] = A[i++];
            }
            else {
                count += (mid - i + 1);
                temp[k++] = A[j++];
            }
        }
        
        while (i <= mid) {
            temp[k++] = A[i++];
        }
        while (j <= right) {
            temp[k++] = A[j++];
        }
        for (int i = left; i <= right; i++)
            A[i] = temp[i];
        
        return count;
    }
    
    int mergeSort(vector<int>& A, vector<int>& temp, int left, int right) {
        int mid, global = 0;
        
        if (right > left) {
            mid = (left + right) / 2;
            global += mergeSort(A, temp, left, mid);
            global += mergeSort(A, temp, mid+1, right);
            global += merge(A, temp, left, mid, right);
        }
        
        return global;
    }
    
    bool isIdealPermutation(vector<int>& A) {
        int global = 0;
        int local = 0;
        int n = A.size();
        vector<int> temp(n);
        
        for (int i = 0; i < n-1; i++) {
            if (A[i] > A[i+1]) local++;
        }
        
        global = mergeSort(A, temp, 0, n-1);
        
        /*
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (A[i] > A[j]) global++;
            }
        }
        */
        
        return global == local;
    }
};