#include<iostream>
#include<vector>
using namespace std;
int bruteForce(vector<int>&gas,vector<int>&cost){
    int size=gas.size();
    for(int i=0;i<size;i++){
        int balance=0;
        int count=0;
        int start=i;
        while(count<size){
            balance+=gas[i];
            if(balance<cost[i]) break;
            balance-=cost[i];
            start=(start+1)%size;
            ++count;
            if(count==size) return start;
        }
    }
    return -1;
}
// Greedy Approach
int frontRear(vector<int>&gas,vector<int>&cost){
    int totalCost=0,totalGas=0,start=0,balance=0,size=gas.size();
    for(int i=0;i<size;i++){
        totalCost+=cost[i];
        totalGas+=gas[i];
    }
    if(totalGas<totalCost) return -1;
    for(int i=0;i<size;i++){
        balance+=gas[i]-cost[i];
        if(balance<0){
            start=i+1;
            balance=0;
        }
    }
    return start;
}
int deficitApproach(vector<int>&gas,vector<int>&cost){
    // Amount of deficiency of gas
    int deficit=0;
    int balance=0;
    int start=0,size=gas.size();
    for(int i=0;i<size;i++){
        balance+=gas[i]-cost[i];
        if(balance<0){
            deficit+=balance;
            start=i+1;
            balance=0;
        }
    }
    if(balance+deficit>=0) return start;
    return -1;
}
int main(){
    vector<int>gas{1,2,3,4,5};
    vector<int>cost{3,4,5,1,2};
    cout<<deficitApproach(gas,cost);
    return 0;
}