1518. Water Bottles
//QUESTION LINK: https://leetcode.com/problems/water-bottles/description/?envType=daily-question&envId=2025-10-01

TOPIC: Math
Simulation


CODE:
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
 
        int empty = numBottles;
        int totalDrinkBottle = numBottles;

        while(empty >= numExchange){

            empty -= numExchange;
            int numBottle = 1;
            
            totalDrinkBottle += numBottle;
            empty += numBottle;
        }
        return totalDrinkBottle;
    }
};
