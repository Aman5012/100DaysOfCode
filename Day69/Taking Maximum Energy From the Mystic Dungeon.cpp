3147. Taking Maximum Energy From the Mystic Dungeon
//QUESTION LINK: https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/description/?envType=daily-question&envId=2025-10-10

TOPIC: Array
Prefix Sum


CODE:

//////////////    brute force  ///////////////////

// Time Complexity: O(n²)
// Space Complexity: O(1)

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int maxiSum = INT_MIN;
        for(int i=0; i<n; i++){
            int sum =energy[i];
            for(int j=i+k;j<n;j = j+k){
                sum = sum+ energy[j];
            }
            maxiSum = max(sum, maxiSum);
        }
        return maxiSum;
    }
};
//////////////////  optimal approach using prefixSum //////////

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        
        vector<int> dp(n, 0);
       
       for(int i= n-1; i>=0; i--){
            if(i+k < n){
                dp[i] = energy[i]+ dp[i+k];
            }else {
                dp[i] =energy[i];
            }
       }
       return *max_element(dp.begin(), dp.end());
    }
};

