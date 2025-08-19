540. Single Element in a Sorted Array
//QUESTION LINK: https://leetcode.com/problems/single-element-in-a-sorted-array/description/

TOPIC: Array
Binary Search


CODE:
/////////////////////////   appproach 1  ///////////////////////////////
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        for(int i=1; i<nums.size(); i +=2){
            if(nums[i]!= nums[i-1]) {
                return nums[i-1];
            
            }
        }
        return nums[nums.size()-1];
    }
};

/////////////////////////   appproach 2 (Bit manipulation )  ///////////////////////////////
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        for(int i=0; i<n; i++){
            ans ^=nums[i];
        }
        return ans;
    }
};


//////////////////////////////////////   optimal appraoch  ////////////////////////////////////
TC: O(log n)
SC: O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(); //size of the array.

    //Edge cases:
    if (n == 1) return nums[0];
    if (nums[0] != nums[1]) return nums[0];
    if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if arr[mid] is the single element:
        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
            return nums[mid];
        }

        //we are in the left:
        if ((mid % 2 == 1 && nums[mid] == nums[mid - 1])
                || (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
            //eliminate the left half:
            low = mid + 1;
        }
        //we are in the right:
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }

    // dummy return statement:
    return -1;
    }
};

