/*You are given an array points containing the coordinates of points on a 2D plane, sorted by the x-values, where points[i] = [xi, yi] such that xi < xj for all 1 <= i < j <= points.length. You are also given an integer k.

Return the maximum value of the equation yi + yj + |xi - xj| where |xi - xj| <= k and 1 <= i < j <= points.length.

It is guaranteed that there exists at least one pair of points that satisfy the constraint |xi - xj| <= k.

 */

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int, int>> dq;  // {yi - xi, xi}
        int maxVal = INT_MIN;
        
        for (const auto& point : points) {
            int x = point[0], y = point[1];
            
            // Remove points that are too far (|xi - xj| > k)
            while (!dq.empty() && x - dq.front().second > k) {
                dq.pop_front();
            }
            
            // Calculate max value for current point
            if (!dq.empty()) {
                maxVal = max(maxVal, dq.front().first + y + x);
            }
            
            // Remove points with smaller yi - xi
            while (!dq.empty() && dq.back().first <= y - x) {
                dq.pop_back();
            }
            
            // Add current point
            dq.push_back({y - x, x});
        }
        
        return maxVal;
    }
};