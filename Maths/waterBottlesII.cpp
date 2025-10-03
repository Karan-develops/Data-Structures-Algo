// LC - 3100 - Medium - Water Bottles II
#include<iostream>
using namespace std;
int maxBottlesDrunk(int numBottles,int numExchange){
    int empty=numBottles;
    int drank=numBottles;

    while(empty>=numExchange){
        empty-=numExchange;

        drank++;
        empty++;

        numExchange++;
    }
    
    return drank;
}
int main(){
    // Output: 15
    int numBottles=13,numExchange=6;
    // Output: 13
    int numBottles2=10,numExchange2=3;
    cout<<maxBottlesDrunk(numBottles,numExchange)<<endl;
    cout<<maxBottlesDrunk(numBottles2,numExchange2);
    return 0;
}