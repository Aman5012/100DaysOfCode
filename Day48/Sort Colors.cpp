75. Sort Colors

//QUESTION LNK: https://leetcode.com/problems/sort-colors/description/

TOPIC: Array
Two Pointers
Sorting


CODE:

// TC:O(n)
// SC:O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low =0, mid =0,  high=n-1;

        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
