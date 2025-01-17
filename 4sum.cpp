/*Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;
        
        // Sort the array
        sort(nums.begin(), nums.end());
        
        for (int a = 0; a < n - 3; a++) {
            // Skip duplicate values for a
            if (a > 0 && nums[a] == nums[a-1]) continue;
            
            for (int b = a + 1; b < n - 2; b++) {
                // Skip duplicate values for b
                if (b > a + 1 && nums[b] == nums[b-1]) continue;
                
                int c = b + 1;
                int d = n - 1;
                
                while (c < d) {
                    long long sum = (long long)nums[a] + nums[b] + nums[c] + nums[d];
                    
                    if (sum == target) {
                        result.push_back({nums[a], nums[b], nums[c], nums[d]});
                        
                        // Skip duplicate values for c and d
                        while (c < d && nums[c] == nums[c+1]) c++;
                        while (c < d && nums[d] == nums[d-1]) d--;
                        
                        c++;
                        d--;
                    } else if (sum < target) {
                        c++;
                    } else {
                        d--;
                    }
                }
            }
        }
        
        return result;
    }
};