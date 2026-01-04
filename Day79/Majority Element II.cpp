229. Majority Element II
//QUESTION LINK: https://leetcode.com/problems/majority-element-ii/description/ 

TOPIC: Array
Hash Table
Sorting
Counting


CODE:

//////////   here only at most Two element can be exist more then than the n/3  //////

//////////////  Boyer-Moore (n/3 case)  /////////////////////
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0;
        int count2=0;

        int candi1=0; 
        int candi2=0;

        for(int num: nums){
            if(count1>0 && candi1 ==num){
                count1++;
            }
            else if(count2 >0 && candi2 == num){
                count2++;
            }
            else if(count1==0){
                candi1= num;
                count1=1; 
            }
            else if(count2==0){
                candi2=num;
                count2=1; 
            }else{
                count1--;
                count2--;
            }
        } 
            // verification pass
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == candi1) count1++;
            else if (num == candi2) count2++;
        }

        vector<int> ans;
        int n = nums.size();
        if (count1 > n / 3) ans.push_back(candi1);
        if (count2 > n / 3) ans.push_back(candi2);
        
        return ans;
    }
};
