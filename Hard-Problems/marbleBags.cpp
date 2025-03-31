// LC - 2551 - HARD - Put Marbles in Bags
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long putMarbles(vector<int>& weights,int k){
    int n=weights.size();
    vector<int>pairSum(n-1,0);
    for(int i=0;i<n-1;i++){
        pairSum[i]=weights[i]+weights[i+1];
    }
    sort(begin(pairSum),end(pairSum));
    long long minSum=0,maxSum=0;
    // K-1 Pairs
    for(int i=0;i<k-1;i++){
        minSum+=pairSum[i];
        maxSum+=pairSum[n-i-2];
    }
    return maxSum-minSum;
}
int main(){
    // Output: 4
    vector<int>weights={1,3,5,1};
    int k=2;
    // Output: 0
    vector<int>weights2={1, 3};
    int k2=2;
    cout<<putMarbles(weights,k)<<endl;
    cout<<putMarbles(weights2,k2);
    return 0;
}