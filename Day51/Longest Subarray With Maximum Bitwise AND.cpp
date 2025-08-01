2419. Longest Subarray With Maximum Bitwise AND
//QUESTION LNK: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/?envType=daily-question&envId=2025-07-30

TOPIC: Array
Bit Manipulation
Brainteaser


CODE:

Time Complexity: O(n)
Space Complexity: O(1)
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int maxLen=0;
        int currLen=0;
        for(int num: nums){
            if(maxVal==num){
                currLen++;
                maxLen = max(maxLen, currLen);
            }else{
                currLen = 0;
            }
        }
        return maxLen;
    }
};
