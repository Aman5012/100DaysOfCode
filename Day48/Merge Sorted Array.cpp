8. Merge Sorted Array

//QUESTION LNK: https://leetcode.com/problems/merge-sorted-array/description/

TOPIC: rray
Two Pointers
Sorting


CODE:

/////////////////////  Appraoch 1  /////////////////////////
class Solution {
    // TC: O((m + n) log(m + n))
    // SC: O(1)
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<n; i++){
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};

//////////////////////////////   Approach 2  /////////////////
class Solution {
    // TC: O(m + n)
    // SC: O(1)
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {


        int i = m-1;
        int j = n-1;
        int k =m+n -1;
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            }
            else{
                nums1[k--] = nums2[j--];
            }
        }
               // If nums2 is not exhausted
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
