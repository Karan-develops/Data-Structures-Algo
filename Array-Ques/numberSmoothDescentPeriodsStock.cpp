// LC - 2110 - Medium - Number of Smooth Descent Periods of a Stock
#include<iostream>
#include<vector>
using namespace std;
long long getDescentPeriods(vector<int>&prices){
    int n=prices.size();

    long long ans=1;
    long long count=1;

    for(int i=1;i<n;i++){
        if(prices[i-1]-prices[i]==1) count++;
        else count=1;
        
        ans+=count;
    }
    return ans;
}
int main(){
    // Output: 7
    vector<int>prices={3,2,1,4};
    // Output: 4
    vector<int>prices2={8,6,7,7};
    // Output: 1
    vector<int>prices3={1};
    cout<<getDescentPeriods(prices)<<endl;
    cout<<getDescentPeriods(prices2)<<endl;
    cout<<getDescentPeriods(prices3);
    return 0;
}