// LC - 1518 - Easy - Water Bottles
// 3 Approaches
#include<iostream>
using namespace std;
// Approach 1 - Simulation
int numWaterBottles1(int numBottles,int numExchange){
    int consumed=0;

    while(numBottles>=numExchange){
        consumed+=numExchange;
        numBottles-=numExchange;

        numBottles+=1;
    }
    return consumed+numBottles;
}
// Approach 2 - Improved Approach 1
int numWaterBottles2(int numBottles,int numExchange){
    int consumed=numBottles;
    int emptyBottles=numBottles;

    while(emptyBottles>=numExchange){
        int extraFullBottles=emptyBottles/numExchange;

        int remain=emptyBottles%numExchange;

        consumed+=extraFullBottles;

        emptyBottles=remain+extraFullBottles;
    }
    return consumed;
}
// Approach 3 - Using Maths
int numWaterBottles(int numBottles,int numExchange){
    return numBottles+(numBottles-1)/(numExchange-1);
}
int main(){
    // Output: 13
    int numBottles=9,numExchange=3;
    // Output: 19
    int numBottles2=15,numExchange2=4;
    cout<<numWaterBottles(numBottles,numExchange)<<endl;
    cout<<numWaterBottles(numBottles2,numExchange2);
    return 0;
}