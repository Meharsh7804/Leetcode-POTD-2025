// 3174. Clear Digits
// You are given a string s.
// Your task is to remove all digits by doing this operation repeatedly:
// Delete the first digit and the closest non-digit character to its left.
// Return the resulting string after removing all digits.

class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

        for (char c : s) {
            if (isdigit(c)) {
                // Remove the closest non-digit character
                if (!st.empty() && !isdigit(st.top())) {
                    st.pop();
                }
            } else {
                st.push(c);
            }
        }

        // Build the resulting string
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        
        return result;
    }
};