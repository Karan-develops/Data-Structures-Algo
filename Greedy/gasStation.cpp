// LC - 134 - Medium - Gas Station
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
// TLE
int bruteForce(vector<int>&gas,vector<int>&cost){
    int n=gas.size();
    
    for(int i=0;i<n;i++){
        if(gas[i]<cost[i]) continue;
        
        int j=(i+1)%n;
        int currGas=gas[i]+gas[j]-cost[i];
        
        while(i!=j){
            if(currGas<cost[j]) break;
            
            int costForMovingFromThisj=cost[j];
            j=(j+1)%n;
            int gasEarnedFromNextStation=gas[j];
            
            currGas=currGas+gasEarnedFromNextStation-costForMovingFromThisj;
        }
        if(i==j) return i;
    }
    return -1;
}
// Greedy
int canCompleteCircuit(vector<int>&gas,vector<int>&cost){
    int n=gas.size();

    int gasSum=accumulate(begin(gas),end(gas),0);
    int costSum=accumulate(begin(cost),end(cost),0);
    
    if(gasSum<costSum) return -1; // Answer nhi milega

    int ans=0,total=0;

    for(int i=0;i<n;i++){
        total+=gas[i]-cost[i];
        if(total<0){
            total=0;
            ans=i+1;
        }
    }
    return ans;
}
int main(){
    // Output: 3
    vector<int>gas={1,2,3,4,5};
    vector<int>cost={3,4,5,1,2};
    // Output: -1
    vector<int>gas2={2,3,4};
    vector<int>cost2={3,4,3};
    cout<<canCompleteCircuit(gas,cost)<<endl;
    cout<<canCompleteCircuit(gas2,cost2);
    return 0;
}