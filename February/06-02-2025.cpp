// 1726. Tuple with Same Product
// Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> product_count;
        int n = nums.size();
        int result = 0;

        // Generate all unique pairs and count their product frequencies
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int product = nums[i] * nums[j];
                product_count[product]++;
            }
        }

        // Calculate the number of valid tuples
        for (auto& entry : product_count) {
            int count = entry.second;
            if (count > 1) {
                result += 8 * (count * (count - 1) / 2);  // 8 * (nC2)
            }
        }

        return result;
    }
};