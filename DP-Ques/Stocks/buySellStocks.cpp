// LC - 121 - Easy - Best Time to Buy and Sell Stock
#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int>&prices){
    int smallest=prices[0],ans=0;

    for(int i=1;i<prices.size();i++){
        smallest=min(smallest,prices[i]);
        ans=max(ans,prices[i]-smallest);
    }
    
    return ans;
}
int main(){
    // Output: 5
    vector<int>prices={7,1,5,3,6,4};
    // Output: 0
    vector<int>prices2={7,6,4,3,1};
    cout<<maxProfit(prices)<<endl;
    cout<<maxProfit(prices2);
    return 0;
}