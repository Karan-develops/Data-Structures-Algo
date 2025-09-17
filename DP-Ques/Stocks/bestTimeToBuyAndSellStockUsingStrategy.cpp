// LC - 3652 - Medium - Best Time to Buy and Sell Stock using Strategy
#include<iostream>
#include<vector>
using namespace std;
long long maxProfit(vector<int>&prices,vector<int>&strategy,int k){
    int n=prices.size();

    long long original=0;
    for(int i=0;i<n;i++){
        original+=(prices[i]*strategy[i]);
    }

    int half=k/2;
    long long change=0;

    for(int i=0;i<half;i++){
        change+=(0*prices[i])-(prices[i]*strategy[i]);
    }
    for(int i=half;i<k;i++){
        change+=(1*prices[i])-(prices[i]*strategy[i]);
    }

    long long ans=change;

    for(int i=1;i<=n-k;i++){
        long long leftI=(prices[i-1]*strategy[i-1]);
        long long midI=(prices[i+half-1]);
        long long rightI=prices[i+k-1]-(prices[i+k-1]*strategy[i+k-1]);

        change+=leftI-midI+rightI;

        ans=max(ans,change);
    }

    return original+max(0LL,ans);
}
int main(){
    // Output: 10
    vector<int>prices={4,2,8},strategy={-1,0,1};
    int k=2;
    // Output: 9
    vector<int>prices2={5,4,3},strategy2={1,1,0};
    int k2=2;
    cout<<maxProfit(prices,strategy,k)<<endl;
    cout<<maxProfit(prices2,strategy2,k2);
    return 0;
}