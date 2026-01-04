35. Search Insert Position
//QUESTION LINK: https://leetcode.com/problems/search-insert-position/

TOPIC: Array
Binary Search


CODE:
/////////////////////////////   simple iteration ///////////////////

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
       int n = nums.size();

       for(int i=0; i<n; i++){
            if(nums[i] == target || nums[i]> target) return i;
       }
       return n;
    }
};

////////////////////////////   binary search    /////////////////////////// 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
       int n = nums.size();

       int low =0;
       int high = n-1;
       int mid;

       if(nums[high]< target) return n;

       while(low <=  high){
            mid = low + (high - low)/2;
            if(target == nums[mid]) return mid;
            else if(target > nums[mid]) low = mid+1;
            else high = mid-1;
       }
       return low;
    }
};


///////////////////////////   using lower bound  /////////////////////
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        // its gives target value index (or just greater than the target value if target is not exist in array  
        auto lb = lower_bound(nums.begin(), nums.end(), target); 
        int start = lb - nums.begin();
        return start;
    }
};
