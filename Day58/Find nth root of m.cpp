Find nth root of m

//QUESTION LINK: https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

TOPIC: MathematicalAlgorithmsBinary Search

CODE:
        //////////////////   binary search  //////////////////////////
        // TC:O(log n)
        // SC: O(1)
        
class Solution {
  public:
    int nthRoot(int n, int m) {
        if(m==0 || m==1|| n==1) return m;
        
        int low=1;
        int high=m;
        while(low<=high){
            int val=1;
            int mid = (low+high)/2;
            for(int i=0; i<n; i++){
                val *=mid;
                if(val>m) break;
            }
            
            if(val == m) return mid;
            else if(val<m) low= mid+1;
            else high = mid-1;
        }
        
        return -1;
        
    }
};
