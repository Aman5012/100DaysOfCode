239. Sliding Window Maximum
//QUESTION LINK: https://leetcode.com/problems/sliding-window-maximum/description/

TOPIC: Array
Queue
Sliding Window
Heap (Priority Queue)
Monotonic Queue


CODE:

//////////////////////////////   brute force  ///////////////////////
// TC: O(n.(n+k)) ~ O(n.n)
// SC: O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0; int r=l+k-1;
        vector<int>temp;
        while(l<=r && r<n){
            int t=l;
            int maxVal = nums[t];
            while(t<=r){
                maxVal= max(maxVal, nums[t]);
                t++;
            }
            temp.push_back(maxVal);
            l++;
            r++;
        }
        return temp;
    }
};

// //////////////////////////   using deque  ///////////////////
// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<int>dq;
       vector<int> ans;

       for(int i=0; i<nums.size(); i++){
            if(!dq.empty() && dq.front()==i-k){ // when window size increses more then k
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]<=nums[i]){ // when back side element are lesser than upComing element 
                dq.pop_back();
            }
            dq.push_back(i);

            if(i>=k-1){
                ans.push_back(nums[dq.front()]); // dq.front()  always keep max element of the window
            }
       }
       return ans;
    }
};
