// 1790. Check if One String Swap Can Make Strings Equal
// You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices. Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2)
            return true;

        vector<int> diffIndices;
        
        // Find indices where s1 and s2 differ
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i])
                diffIndices.push_back(i);
        }
        
        // If there are not exactly 2 mismatches, return false
        if (diffIndices.size() != 2)
            return false;

        // Check if swapping the two differing characters makes the strings equal
        swap(s1[diffIndices[0]], s1[diffIndices[1]]);
        
        return s1 == s2;
    }
};
