// 3160. Find the Number of Distinct Colors Among the Balls
// You are given an integer limit and a 2D array queries of size n x 2.
// There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, you need to find the number of distinct colors among the balls.
// Return an array result of length n, where result[i] denotes the number of distinct colors after ith query.
// Note that when answering a query, lack of a color will not be considered as a color.

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor; // Maps ball -> color
        unordered_set<int> uniqueColors;   // Stores unique colors
        vector<int> result;

        for (auto& query : queries) {
            int ball = query[0], color = query[1];

            // Check if the ball already has a color
            if (ballColor.count(ball)) {
                int prevColor = ballColor[ball];
                
                // If changing color, check if previous color needs to be removed
                if (prevColor != color) {
                    ballColor[ball] = color;
                    
                    // Remove previous color if no other ball has it
                    if (!any_of(ballColor.begin(), ballColor.end(), 
                                [&](const auto& p) { return p.second == prevColor; })) {
                        uniqueColors.erase(prevColor);
                    }
                }
            } else {
                // New color assignment
                ballColor[ball] = color;
            }
            
            uniqueColors.insert(color);
            result.push_back(uniqueColors.size());
        }

        return result;
    }
};