// LC - 3652 - Medium - Best Time to Buy and Sell Stock using Strategy
#include<iostream>
#include<vector>
using namespace std;
class SlidingWindow{
    typedef long long ll;
    public:
    long long maxProfit(vector<int>&prices,vector<int>&strategy,int k){
        int n=prices.size();

        ll actualProfit=0;
        vector<ll>profit(n);

        for(int i=0;i<n;i++){
            profit[i]=(ll)strategy[i]*prices[i];
            actualProfit+=profit[i];
        }

        ll originalWindowProfit=0;
        ll modifiedWindowProfit=0;
        ll maxGain=0; // modifiedWindowProfit - originalWindowProfit

        int i=0,j=0;

        while(j<n){
            originalWindowProfit+=profit[j];
            
            // Second half of the window contributes to modifiedWindowProfit
            if(j-i+1>k/2){
                modifiedWindowProfit+=prices[j];
            }

            if(j-i+1>k){
                originalWindowProfit-=profit[i];
                modifiedWindowProfit-=prices[i+k/2];
                i++;
            }

            if(j-i+1==k){
                maxGain=max(maxGain,modifiedWindowProfit-originalWindowProfit);
            }

            j++;
        }

        return actualProfit+maxGain;
    }
};
int main(){
    // Output: 10
    vector<int>prices={4,2,8},strategy={-1,0,1};
    int k=2;
    // Output: 9
    vector<int>prices2={5,4,3},strategy2={1,1,0};
    int k2=2;

    SlidingWindow sol;
    cout<<sol.maxProfit(prices,strategy,k)<<endl;
    cout<<sol.maxProfit(prices2,strategy2,k2);
    return 0;
}