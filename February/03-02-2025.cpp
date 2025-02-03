// 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
// You are given an array of integers nums. Return the length of the longest subarray of nums which is either strictly increasing or strictly decreasing.

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.size() == 1) return 1;  // If only one element, return 1
        
        int inc = 1, dec = 1, maxLength = 1; 
        
        for(int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                inc++;
                dec = 1;  // Reset decreasing count
            } else if (nums[i] < nums[i - 1]) {
                dec++;
                inc = 1;  // Reset increasing count
            } else {
                inc = 1;
                dec = 1;
            }
            maxLength = max(maxLength, max(inc, dec));
        }
        
        return maxLength;
    }
};
