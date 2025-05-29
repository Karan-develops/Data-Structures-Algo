// LC - 2706 - Easy - Buy Two Chocolates
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int buyChoco(vector<int>&prices,int money){
    sort(begin(prices),end(prices));
    int total=prices[0]+prices[1];
    if (total<=money) return money-total;
    return money;
}
int main(){
    // Output: 0
    vector<int>prices={1,2,2};
    int money=3;
    // Output: 3
    vector<int>prices2={3,2,3};
    int money2=3;
    cout<<buyChoco(prices,money)<<endl;
    cout<<buyChoco(prices2,money2);
    return 0;
}