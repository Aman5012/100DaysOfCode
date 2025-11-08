3318. Find X-Sum of All K-Long Subarrays I
//QUESTION LINK: https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/description/?envType=daily-question&envId=2025-11-04

// TOPIC: Array
// Hash Table
// Sliding Window
// Heap (Priority Queue)


CODE:
// TC: O(n * (k log k))
// SC: O(n*k)

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n= nums.size();
        for(int i=0; i<= n-k; i++){
            unordered_map<int, int>mp;
           for(int j=i; j<i+k; j++){
                mp[nums[j]]++;
           }
           vector<pair<int,int>> vec(mp.begin(), mp.end());
            sort(vec.begin(), vec.end(), [](pair<int,int>& a, pair<int,int>& b){
                if(a.second == b.second)
                    return a.first > b.first;
                return a.second > b.second;
            });

            int sum = 0, count = 0;
            for(auto &p : vec){
                if(count == x) break;
                sum += p.first * p.second;
                count++;
            }
            ans.push_back(sum);
        }
        return ans;
       
    }
};
