2302. Count Subarrays With Score Less Than K
//QUESTION LINK: https://leetcode.com/problems/count-subarrays-with-score-less-than-k/

// TOPIC: Array
// Binary Search
// Sliding Window
// Prefix Sum


CODE:
////////////////////////////  brute fore  ///////////////////
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int count =0;


        for(int left =0; left<n ; left++){
            long long sum =0;

            for(int right= left; right<n; right++){
                sum += nums[right];
                if(sum * (right - left+1)<k){
                    count ++;
                } else break;
            }
        }
        return   count;
    }
};

////////////////////////  sliding window ///////////////////////
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int start = 0;
        long long currentSum = 0;
        long long totalCount = 0;

            // sliding windoe appraoch 
        for(int end= 0; end<n; end++){
            currentSum += nums[end];
            // when condition fails we shrink the window
            while(start <=end && currentSum * (end - start + 1) >= k){
                currentSum -= nums[start++];
            }
            // updating the total count 
            totalCount += end - start +1; 
        }

        return totalCount;
    }
};
