3346. Maximum Frequency of an Element After Performing Operations I

//QUESTION LINK: https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/description/?envType=daily-question&envId=2025-10-21

TOPIC: Array
Binary Search
Sliding Window
Sorting
Prefix Sum


CODE:
///////////////////////optimal solution(diff array + map) ///////////

TC: O(n+maxVal)
SC: O(n+maxVal)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int result =0;
        unordered_map<int, int> freq;
        vector<int> diff(maxVal+2, 0);

        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;

            int l= max(0, nums[i]-k);
            int r= min(nums[i]+k, maxVal);

            diff[l]++;
            diff[r+1]--;
        } 

        for(int target=0; target<=maxVal; target++){
            if(target > 0) diff[target] += diff[target-1]; 
               
            int need_to_convert = diff[target] - freq[target];
            int maxPossible_cahnge = min(numOperations, need_to_convert);

            result = max(result, maxPossible_cahnge + freq[target]);
        }
        return result;
    }
};

/////////////////////////  brute force (TLE) /////////////////////////
TC: O(n²)
SC: O(n)

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_set<int> candidate;

        for(int x: nums){
            candidate.insert(x);
            candidate.insert(x-k);
            candidate.insert(x+k);
        }
        int maxiFreq=0;

        for(int target: candidate){
            
            int unchange=0;
            int changeable=0;


            for(int num: nums){
                if(num == target) unchange++;
                else if(abs(target-num)<=k) changeable++;

                int currFreq = unchange + min(changeable, numOperations);

                maxiFreq = max(maxiFreq, currFreq);
            }
        }
        return maxiFreq;
    }
};
