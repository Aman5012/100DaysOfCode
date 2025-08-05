3477. Fruits Into Baskets II
//QUESTION LNK: https://leetcode.com/problems/fruits-into-baskets-ii/?envType=daily-question&envId=2025-08-05

TOPIC: Array
Binary Search
Segment Tree
Simulation
Ordered Set



CODE:
// TC: O(n.n)
// SC: O(1)
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int count =0;
        
        for(int fruit: fruits){
            int unset=1;
            for(int j=0; j<n; j++){
                if(fruit<= baskets[j]){
                    baskets[j]=0;       // mark basket is used
                    unset=0;            // fruit is placed
                    break;              // exit the inner loop
                }
            }
            count +=unset;
        }
        return count;
    }
};
