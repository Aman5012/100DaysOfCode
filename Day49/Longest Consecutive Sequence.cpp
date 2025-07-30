128. Longest Consecutive Sequence

//QUESTION LNK: https://leetcode.com/problems/longest-consecutive-sequence/description/

// TOPIC: rray
// Hash Table
// Union Find


CODE:

////////////////////  optimal approach  /////////////
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int>s;
        int largest=1;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }

        for(int num: s){
            if(s.find(num-1)==s.end()){
                int count =1;
                int x =num;
                while(s.find(x+1)!= s.end()){
                    count++;
                    x++;
                }
                largest = max(largest, count);
            }
        }
        return largest;
        
    }
};

////////////////////////////  sorting appraoch  ///////////////
// TC: O(n log n)
// SC: O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int maxLen = 1, currLen = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) continue; // Skip duplicates
            else if (nums[i] == nums[i - 1] + 1) currLen++;
            else currLen = 1;

            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};
