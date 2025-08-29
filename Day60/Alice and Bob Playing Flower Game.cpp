3021. Alice and Bob Playing Flower Game

//QUESTION LINK: https://leetcode.com/problems/alice-and-bob-playing-flower-game/description/?envType=daily-question&envId=2025-08-29

TOPIC: Math

CODE:

///////////////////////   brute force  ///////////////
// TC: O(n²)
// SC: O(n)
class Solution {
public:
    long long flowerGame(int n, int m) {
        int count=0;
        for(int a=0; a<n; a++){
            for(int b=0; b<m; b++){
                if((b+a) &1) count++;
            }
        }
        return count;
    }
};

/////////////////////////////////  optimal approach  ///////////////////////////
TC: O(n)
SC: O(1)
class Solution {
public:
    long long flowerGame(int n, int m) {
        long long  count=0;
        long long oddC =0;
        long long evenC =0;

        for(int i = 1; i<=m; i++){
            if(i&1){                    // check odd condition
                oddC++;
            }else{                      // i is even 
                evenC++;
            }
        }

        for(int num = 1; num <=n ; num + +) {
            if(num & 1)  count += evenC;  // num is odd then add evenC 
            else count+=oddC;
        }

        return count;
    }
};
