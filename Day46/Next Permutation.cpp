31. Next Permutation

//QUESTION LNK: https://leetcode.com/problems/next-permutation/

TOPIC: Array, Two Pointers

CODE:

// Time Complexity: O(n) 
// Space Complexity: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=-1;
        int n = nums.size();

        for(int i= n-2; i>=0; --i){
            if(nums[i]<nums[i+1])
            {
                index =i;
                break;
            }
        }
        if(index==-1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i= n-1; i>=index; --i){
            if(nums[i]>nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1, nums.end());
        return;
    }
};





// ///////////////////////   using stl library  /////////////////
// Time Complexity: O(n) 
// Space Complexity: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
        return;
    }
};
