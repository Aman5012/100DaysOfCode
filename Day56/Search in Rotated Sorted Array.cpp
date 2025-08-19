33. Search in Rotated Sorted Array
//QUESTION LINK: https://leetcode.com/problems/search-in-rotated-sorted-array/description/

TOPIC: Array
Binary Search


CODE:
// TC: O(log n)
// SC: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n =nums.size();
        int low=0; 
        int high=n-1;

        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]== target) return mid;

            if(nums[low]<=nums[mid]){
                // left half
                if(target >=nums[low] && target <=nums[mid]){
                    high =mid-1;
                }else{
                    low = mid+1;
                }
            }else{
                    // right half
                if(target >=nums[mid] && target <=nums[high]){
                    low =mid+1;
                }else{
                    high = mid-1;
                }

            }
        }
        return -1;
    }
};
