15. 3Sum
//QUESTION LNK: https://leetcode.com/problems/3sum/

TOPIC: Array
Two Pointers
Sorting


CODE:

//////////////////////////////////////////////   optimal approach    ////////////////////////////////////
// TC: O(n.n)
// SC: O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int  n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue; // prevent from duplication
            int j = i+1;
            int k=n-1;
            while(j<k){
                int sum  = nums[i]+ nums[j]+ nums[k];
                if(sum <0){
                    j++;
                }else if(sum>0){
                    k--;
                }else{
                    vector<int> temp = {nums[i],nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]) j++; // prevent from duplication
                    while(j<k && nums[k] == nums[k+1]) k--; // prevent from duplication
                }
            }
        }
        return ans;
    }
};


////////////////////////////////   brute force (TLE expected)  /////////////////
// TC: O(n.n.n)
// SC: O(n)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> uniqueTriplets;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=1+i; j<n; j++){
                for(int k=0; k<n; k++){
                    if(k==i || k== j) continue;
                    int sum =nums[i]+ nums[j]+ nums[k];

                    if(sum ==0){
                        vector<int>temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        uniqueTriplets.insert(temp);
                    }
                }
            }
        }

        for(const auto& t:uniqueTriplets ){
            ans.push_back(t);
        }
        return ans;
    }
};
