// 1980. Find Unique Binary String
// Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> numSet(nums.begin(), nums.end()); // Store nums in a set for quick lookup
        
        // Generate all possible binary strings of length n
        for (int i = 0; i < (1 << n); i++) {
            string candidate = bitset<16>(i).to_string().substr(16 - n); // Convert number to n-bit binary
            if (numSet.find(candidate) == numSet.end()) {
                return candidate; // Return the first missing binary string
            }
        }
        return ""   
    }
};
