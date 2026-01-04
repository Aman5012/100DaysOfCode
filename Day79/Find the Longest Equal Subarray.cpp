2831. Find the Longest Equal Subarray
//QUESTION LINK: https://leetcode.com/problems/find-the-longest-equal-subarray/

TOPIC: Array
Hash Table
Binary Search
Sliding Window


CODE:
////////////////////////////   brute force solution  ///////////
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0) return 0;
        int ans=0;
        for(int i=0; i<n; i++){
            int temp=k;
            int target =nums[i];
            int j=i+1;
            int longest=1;
            while(temp>=0 && j<n){
                if(temp == 0 && nums[j]!=target) break;

                if(nums[j] == target){
                    longest++;
                }else{
                    temp--;  
                }
                    j++;
            }

            ans = max(ans, longest);
            
        }
        return ans;
    }
};


//////////////////////////   optimal solution sliding window  ////////////////
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos; // sore the position of each uique element
        int ans=0;
        for(int i=0; i<n; i++){
            pos[nums[i]].push_back(i);
        }


        for(auto &it: pos){
            auto &idx = it.second;

            int i=0;
            for(int j=0; j< idx.size(); j++){
                while((idx[j]- idx[i]) - (j-i) >k){ // total number that can be deleted in window
                    i++;
                }
            ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};

////////////////////////////////////////////////  appraoch 3  //////////////////////

class Solution {
public:
    int longestEqualSubarray(vector<int>& N, int k) 
    {
        int i =0, j=0;
        unordered_map<int,int>mp;
        int mx_freq = 1;
        while(j< N.size())
        {
            mp[N[j]]++;
            mx_freq = max(mx_freq, mp[N[j]]);
            int total_elems = j-i+1;
            if(total_elems - mx_freq > k){
                mp[N[i]]--;
                i++;
            }
            j++;
        }
        return mx_freq;
    }
};
