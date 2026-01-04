34. Find First and Last Position of Element in Sorted Array
//QUESTION LINK: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

TOPIC: Array
Binary Search


CODE:
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto iterator1 = lower_bound(nums.begin(), nums.end(), target); // this store a addres value of that value where the target exist

        if(iterator1 == nums.end() || *iterator1 != target){
            return {-1, -1};
        }
        auto iterator2 = upper_bound(nums.begin(), nums.end(), target); // its give the index just greater than the target value

        // int start = distance(nums.begin(), l_b);
        // int end = distance(nums.begin(), u_b) -1;

        // Using subtraction to get indices
        int start = iterator1 - nums.begin();
        int end = (iterator2 - nums.begin()) - 1;


        return {start, end};
    }
};
