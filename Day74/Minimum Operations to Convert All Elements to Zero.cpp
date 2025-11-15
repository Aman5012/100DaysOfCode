3542. Minimum Operations to Convert All Elements to Zero
//QUESTION LINK: https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/?envType=daily-question&envId=2025-11-10

// TOPIC: Array
// Hash Table
// Stack
// Greedy
// Monotonic Stack


CODE:
//////////////////////////  brute force (TLE)   ////////////////
// Time Complexity: O(n²)
// Space Complexity: O(1)

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int step=0;
        while(true){
            int l=0;
            while(l<n && nums[l]==0) l++;
            if(l==n) break;
            int r=l;
            int mini  =INT_MAX;
            while(l<n &&  r<n && nums[r]!=0){
                mini = min(nums[r], mini);
                r++;
            }
            for(int s=l; s<r; s++){
                if(nums[s]== mini) nums[s]=0; 
            }
            step++;
        }
        return step;
    }
};

//////////////////////////  optimal approach ///////////////////
// Time Complexity: O(n²)
// Space Complexity: O(1)

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int step=0;
        stack<int> st;
        
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top()> nums[i]){
                st.pop();
            }
            if(nums[i]==0) continue;

            while(st.empty() || st.top()< nums[i]){
                step++;
                st.push(nums[i]);
            }
        }
        return step;
    }
};

