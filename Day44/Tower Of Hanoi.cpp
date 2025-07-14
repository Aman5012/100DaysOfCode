Tower Of Hanoi

//QUESTION LNK: https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1

TOPIC: recursion


CODE:

// Time Complexity:  O(2ⁿ)
// Space Complexity: O(n)

class Solution {
  public:
  
    int count = 0;
    void solve(int n, int from, int to, int aux){
        if(n == 1) {
            count++;
            return;
        }
        solve(n - 1, from, aux, to); // move n-1 disks from 'from' to 'aux'
        count++;                    // move the nth disk to 'to'
        solve(n - 1, aux, to, from); // move n-1 disks from 'aux' to 'to'
    }

    int towerOfHanoi(int n, int from, int to, int aux) {
        solve(n, from, to, aux);
        return count;
    }
};
