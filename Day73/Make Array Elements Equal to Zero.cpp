3354. Make Array Elements Equal to Zero
//QUESTION LINK: https://leetcode.com/problems/make-array-elements-equal-to-zero/?envType=daily-question&envId=2025-10-28

TOPIC: Array
Simulation
Prefix Sum


CODE:
//////////////////////  optimal appraoch ////////////////////////

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int validSelection=0;
        int n= nums.size();

        vector<int> ps(n + 1, 0);
        for(int i = 1; i <= n; i++){
            ps[i] = ps[i - 1] + nums[i - 1];
        }
        
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                int left  = ps[i];        
                int right = ps[n] - ps[i]; 

                if(left == right) validSelection += 2;
                if(left + 1 == right || left == right + 1) validSelection++;
            }
        }
        return validSelection;
    }
};



////////////////////////   brute force   /////////////////////////////
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int validSelection=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){

                int check =i;
                int leftSum=0;
                int rightSum=0;
                int checkLeft=check;
                int checkright=check;
                while(checkLeft>=0){
                    leftSum += nums[checkLeft];
                    checkLeft--;
                }
                while(checkright<nums.size()){
                    rightSum += nums[checkright];
                    checkright++;
                }
            if(leftSum == rightSum ) validSelection +=2;
            if( leftSum+1 == rightSum || leftSum == rightSum+1 ) validSelection ++;
            }

        }
        return validSelection;
    }
};

