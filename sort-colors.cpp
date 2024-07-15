/*Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;  // pointer for 0 (red)
        int mid = 0;  // pointer for 1 (white)
        int high = nums.size() - 1;  // pointer for 2 (blue)
        
        while (mid <= high) {
            switch (nums[mid]) {
                case 0:
                    swap(nums[low], nums[mid]);
                    low++;
                    mid++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid], nums[high]);
                    high--;
                    break;
            }
        }
    }
    
private:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};