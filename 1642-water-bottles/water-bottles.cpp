class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumed=0;
        while(numBottles>=numExchange){
            int temp=numBottles/numExchange;
            consumed+=numExchange*temp;
            numBottles-=numExchange*temp;
            numBottles+=temp;
        }
        return consumed+numBottles;
    }
};