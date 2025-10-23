397. Maximum Number of Distinct Elements After Operations
//QUESTION LINK: https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/?envType=daily-question&envId=2025-10-18

TOPIC: Array
Greedy
Sorting



CODE:
////////////////////////  brute force appraoch ///////////////////////////
// TC: O(n²)
// SC: O(n)

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        unordered_set<int>st;
        
        for(int num: nums){
            for(int d= -k; d<=k; d++){
                int newNum = num+d;
                if(!st.count(newNum)){
                    st.insert(newNum);
                    break;
                }
            }
        }
        
        return st.size();
    }
};
// //////////////////////  optimal approach //////////////////////////
// TC: O(n log n)
// SC: O(n)

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt=0, prev = INT_MIN;

        for(int x: nums){
            int curr = min(max(x - k, prev+1), x+k);
            if(curr>prev){
                cnt++;
                prev=curr;
            }
        }
        return cnt;
    }
};
