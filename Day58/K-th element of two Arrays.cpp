K-th element of two Arrays

//QUESTION LINK: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

TOPIC: ArraysDivide and ConquerData StructuresAlgorithmsBinary Search


CODE:
////////////////////////   binary appraoch //////////////////
// TC: O(log min(m,n))
// SC: O(1)
class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int m = a.size(), n = b.size();

        // ensure a is the smaller array
        if (m > n) return kthElement(b, a, k);

        int low = max(0, k - n), high = min(k, m);

        while (low <= high) {
            int cut1 = (low + high) >> 1;
            int cut2 = k - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];

            int r1 = (cut1 == m) ? INT_MAX : a[cut1];
            int r2 = (cut2 == n) ? INT_MAX : b[cut2];

            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } else if (l1 > r2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }
        return -1; // should not reach here
    }
};
 

// ////////////////////////   two pointer appraoch //////////////////
// // TC: O(m + n)
// // SC: O(1)
class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int m= a.size();
        int n= b.size();
        int i=0;
        int j=0;
        int count=0;
        int ans=0;
        while(i<m && j<n){
            if(a[i]<b[j]){
                ans=a[i];
                i++;
            }else{
                ans=b[j];
                j++;
            }
            count++;
            if(count==k) return ans;
        }
        
        while(j<n){
            ans =b[j];
            j++;
            count++;
            if(count==k) return ans;
        }
        while(i<m){
            ans =a[i];
            i++;
            count++;
            if(count==k) return ans;
        }
        return -1;
    }
};   


// ///////////////////////   using heap   //////////////////////////

// // TC: O((m + n) log k)
// // SC: O(k)

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
             priority_queue<int> maxHeap;  // max-heap

        // push all elements from both arrays
        for (int x : a) {
            maxHeap.push(x);
            if (maxHeap.size() > k) maxHeap.pop(); // keep only k smallest
        }
        for (int x : b) {
            maxHeap.push(x);
            if (maxHeap.size() > k) maxHeap.pop(); // keep only k smallest
        }

        return maxHeap.top(); // the k-th smallest
    }
};

// ///////////////////////   using heap + two pointer appraoch    //////////////////////////

// TC: O(k log k)
// SC: O(k)

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int m= a.size();
        int n= b.size();
        int i=0;
        int j=0;
        
        priority_queue<int> maxHeap;
        
        while(i<m && j<n){
            if(a[i]<b[j]){
                maxHeap.push(a[i]);
                i++;
            }else{
                maxHeap.push(b[j]);
                j++;
            } 
            
            if(maxHeap.size()==k) return maxHeap.top();
        }
        
        //  if m>n 
        while(i<m){
                maxHeap.push(a[i]);
                i++;
            if(maxHeap.size()==k) return maxHeap.top();
        }
        // if n>m
        while(j<n){
                maxHeap.push(b[j]);
                j++;
            if(maxHeap.size()==k) return maxHeap.top();
        }
        
        return -1;
    }
};



