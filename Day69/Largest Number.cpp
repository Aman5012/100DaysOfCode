179. Largest Number
//QUESTION LINK: https://leetcode.com/problems/largest-number/description/

TOPIC: Array
String
Greedy
Sorting


CODE:

///////////////////  brute force appraoch //////////////////////////
// TC: O(n² × d)
// SC: O(n × d)
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        int n= nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                string s1 = to_string(nums[i]) + to_string(nums[j]); 
                string s2 = to_string(nums[j]) + to_string(nums[i]); 
                if(s1<s2) swap(nums[i], nums[j]);
            }
        }
        
        if (nums[0] == 0) return "0";
        for(int i=0; i<n ; i++){
            cout<<nums[i]<<" ";
        }
            string res="";
        for(int x: nums){
             res +=to_string(x); 
        }
        return res;
    }
};

////////////////////////   STL sorting mrthod  ////////////////

// TC: O(n log n × d)
// SC: O(n × d)
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });

        if (nums[0] == 0) return "0";

        string res = "";
        for (int x : nums) res += to_string(x);
        return res;
    }
};


