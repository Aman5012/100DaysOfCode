33. Search in Rotated Sorted Array
//QUESTION LINK: https://leetcode.com/problems/search-in-rotated-sorted-array/

TOPIC: Array
Binary Search


CODE:
/////////////////////////////   TC:  O(log n)//////////////
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int low=0; 
        int high= n-1;

        while(low<=high){
            int mid= low + (high-low)/2;

            if(nums[mid]== target) return mid;

            if(nums[low]<=nums[mid]){
                if(nums[low] <= target && target < nums[mid]){
                    high = mid-1;
                }else {
                    low = mid+1;
                }
            }else{
                if(nums[mid] < target && target <= nums[high]){
                    low= mid+1;
                }else {
                    high = mid-1;
                }
            }
        }
        return -1; 
    }
};





///////////////////////////  TC: O(n)  //////////////////////////
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int low, high ;
        int pivotIndex = n - 1;
        for(int i=1; i<n; i++){
            if(nums[i]<nums[i-1]) pivotIndex=i-1;
        }
        if(target < nums[0]){
            low = pivotIndex+1;
            high=n-1;
            while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
            }
        }else{
            low=0;
            high = pivotIndex;
            while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
            }
        }
        return -1; 
    }
};

