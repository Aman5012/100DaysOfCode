3100. Water Bottles II
//QUESTION LINK: https://leetcode.com/problems/water-bottles-ii/?envType=daily-question&envId=2025-10-02

TOPIC: Math
Simulation


CODE:
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = numBottles;
        int totalDrinkBottle = numBottles;

        while(empty >= numExchange){

            empty -= numExchange;
            // when one group ix exvhanged then numExchange in crease by one
            numExchange++;
            int numBottle = 1;
            
            totalDrinkBottle += numBottle;
            empty += numBottle;
        }
        return totalDrinkBottle;
    }
};
