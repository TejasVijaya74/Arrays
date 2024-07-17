/*Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;  // Initialize with 0 sum seen once
        
        int count = 0;
        int sum = 0;
        
        for (int num : nums) {
            sum += num;
            
            // Take modulo to handle negative numbers correctly
            int remainder = (sum % k + k) % k;
            
            // If we've seen this remainder before, it means we can form subarrays
            count += prefixSumCount[remainder];
            
            // Increment the count of this remainder
            prefixSumCount[remainder]++;
        }
        
        return count;
    }
};