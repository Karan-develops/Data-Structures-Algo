// GFG - Shop in Candy Store
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> minMaxCandy(vector<int>&prices,int k){
    int n=prices.size();
    
    sort(begin(prices),end(prices));
    
    int minSum=0,maxSum=0;
    
    int i=0,j=n-1;
    while(i<=j){
        minSum+=prices[i++];
        j-=k;
    }
    
    i=0,j=n-1;
    while(i<=j){
        maxSum+=prices[j--];
        i+=k;
    }
    return {minSum,maxSum};
}
int main(){
    // Output: [3, 7]
    vector<int>prices={3,2,1,4};
    int k=2;
    // Output: [1, 5]
    vector<int>prices2={3,2,1,4,5};
    int k2=4;
    return 0;
}