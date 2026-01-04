278. First Bad Version

//QUESTION LINK: https://leetcode.com/problems/first-bad-version/

TOPIC: Binary Search
Interactive


CODE:
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s=1;
        int l =n;
        int mid;

        while(s<l){
            mid = s+ (l-s)/2;

            if(isBadVersion(mid)){
                l = mid;  
            }else s = mid +1;
        }
    return s;
    }
};
