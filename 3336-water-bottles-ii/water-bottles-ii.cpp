class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = numBottles;   // initially, all full bottles will become empty after drinking
        int drank = numBottles;   // total bottles drunk so far

        // while we have enough empty bottles to exchange (>= not >)
        while (empty >= numExchange) {
            empty -= numExchange; // spend 'numExchange' empty bottles to get 1 new full bottle
            drank++;              // we drink that new full bottle
            empty++;              // drinking it gives us 1 more empty bottle back
            numExchange++;        // after each exchange, the cost increases by 1
        }

        return drank; // return total bottles drunk
    }
};
