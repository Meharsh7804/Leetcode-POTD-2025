// 1749. Maximum Absolute Sum of Any Subarray
// Hint
// You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

// Return the maximum absolute sum of any (possibly empty) subarray of nums.

// Note that abs(x) is defined as follows:

// If x is a negative integer, then abs(x) = -x.
// If x is a non-negative integer, then abs(x) = x.

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0;
        int currMax = 0, currMin = 0;

        for (int num : nums) {
            currMax = max(num, currMax + num);
            maxSum = max(maxSum, currMax);
            
            currMin = min(num, currMin + num);
            minSum = min(minSum, currMin);
        }

        return max(maxSum, abs(minSum));
    }
};