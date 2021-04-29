class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 0)
            return false;
        int low = 0;
        int high = 32;
        while (low <= high) {
            int mid = (low + high) / 2;
            long long p = pow(3, mid);
            if (p == n)
                return true;
            else if (p > n)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
};