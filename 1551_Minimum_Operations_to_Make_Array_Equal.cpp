class Solution {
public:
    int minOperations(int n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = (2 * i) + 1;
        }
        
        int count = 0;
        
        for (int i = 0, j = n-1; i < j; i++, j--) {
            count += (arr[j] - arr[i]) / 2;
        }
        
        return count;
    }
};