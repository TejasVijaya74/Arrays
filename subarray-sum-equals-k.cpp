/*Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumFreq;
        int count = 0;
        int sum = 0;
        
        // Initialize the frequency of sum 0 to 1
        sumFreq[0] = 1;
        
        for (int num : nums) {
            // Calculate cumulative sum
            sum += num;
            
            // If (sum - k) exists in map, add its frequency to count
            if (sumFreq.find(sum - k) != sumFreq.end()) {
                count += sumFreq[sum - k];
            }
            
            // Increment the frequency of current sum
            sumFreq[sum]++;
        }
        
        return count;
    }
};