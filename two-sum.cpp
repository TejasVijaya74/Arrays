/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i};
            }
            
            num_map[nums[i]] = i;
        }
        
        // If no solution is found
        return {};
    }
};