// 1524. Number of Sub-arrays With Odd Sum
// Given an array of integers arr, return the number of subarrays with an odd sum.
// Since the answer can be very large, return it modulo 10^9 + 7.

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int odd_count = 0, even_count = 1;  // Start with 1 even count (empty prefix)
        int prefix_sum = 0, result = 0;

        for (int num : arr) {
            prefix_sum += num;
            
            if (prefix_sum % 2 == 0) {
                result = (result + odd_count) % MOD;
                even_count++;
            } else {
                result = (result + even_count) % MOD;
                odd_count++;
            }
        }

        return result;
    }
};
