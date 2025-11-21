437. Check If All 1's Are at Least Length K Places Away
//QUESTION LINK: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/?envType=daily-question&envId=2025-11-17

TOPIC: Array


CODE:
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n= nums.size();
        
        int left = 0;
        while(left<n){
            if(nums[left] == 0) left++;
            else break;
        }
        int right=left+1;
        while(left<n && right < n){
            if(nums[right]==1){
                if(right-left-1 >= k){
                    left=right; 
                }else{
                    return false;
                }
            }
            right++;
        }
        return true;
    }
};
