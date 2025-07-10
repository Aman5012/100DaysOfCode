2311. Longest Binary Subsequence Less Than or Equal to K 

//QUESTION LNK: https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/?envType=daily-question&envId=2025-06-26

// TOPIC: greedy


// CODE:

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        int powerVal=1;
        int length =0;
         for(int i=n-1; i>=0; i--){
            if(s[i]=='0') length++;
            else if(powerVal <=k){
                k = k- powerVal;
                length++;
            }
            if(powerVal<=k){
                powerVal<<=1;// power *=2
            }
         }
         return length;  
    }
};
