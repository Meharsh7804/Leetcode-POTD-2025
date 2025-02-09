// 2364. Count Number of Bad Pairs
// You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i]. Return the total number of bad pairs in nums.

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> freq;
        long long goodPairs = 0, n = nums.size();

        for (int j = 0; j < n; j++) {
            int diff = nums[j] - j;
            goodPairs += freq[diff];  // Count previous occurrences of this diff
            freq[diff]++;  // Update frequency map
        }

        long long totalPairs = (n * (n - 1)) / 2;
        return totalPairs - goodPairs;  // Bad pairs = total - good
    }
};