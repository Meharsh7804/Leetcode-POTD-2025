// 3151. Special Array I
// An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
// You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.

#include <stdio.h>
#include <vector>

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++) {
            if ((nums[i] % 2) == (nums[i - 1] % 2)) {  // If adjacent numbers have the same parity
                return false;
            }
        }
        return true;  // If all pairs have different parity
    }
};
