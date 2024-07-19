/*Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].*/

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
    
private:
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        
        int mid = left + (right - left) / 2;
        int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);
        
        count += merge(nums, left, mid, right);
        
        return count;
    }
    
    int merge(vector<int>& nums, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += j - (mid + 1);
        }
        
        vector<int> temp(right - left + 1);
        int i = left, k = mid + 1, p = 0;
        
        while (i <= mid && k <= right) {
            if (nums[i] <= nums[k]) {
                temp[p++] = nums[i++];
            } else {
                temp[p++] = nums[k++];
            }
        }
        
        while (i <= mid) temp[p++] = nums[i++];
        while (k <= right) temp[p++] = nums[k++];
        
        for (int q = 0; q < temp.size(); q++) {
            nums[left + q] = temp[q];
        }
        
        return count;
    }
};