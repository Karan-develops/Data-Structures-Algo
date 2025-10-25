// LC - 1716 - Easy - Calculate Money in Leetcode Bank
// 2 Approaches
#include<iostream>
using namespace std;
// Approach 1 - O(n)
int totalMoney(int n){
    int ans=0;
    int extra=0;

    while(n>0){
        for(int day=1;day<=min(n,7);day++){
            ans+=(day+extra);
        }
        n-=7;
        extra++;
    }

    return ans;
}
// Approach 2 - Using Maths
int totalMoneyMaths(int n){
    int items=n/7;
    int first=28;
    int last=28+(items-1)*7; // Tn = a1 + (n-1)*d
    
    int arithmeticSum=items*(first+last)/2; // Sn = n/2(a1 + an)
    
    // Final week remaining days
    int monday_money=1+items;
    int finalWeek=0;
    
    // This loop will Never iterate more than 6 ~ O(1)
    for(int day=1;day<=(n%7);day++){
        finalWeek+=monday_money++;
    }
    
    return arithmeticSum+finalWeek;
}
int main(){
    // Output: 10
    int n=4;
    // Output: 37
    int n2=10;
    // Output: 96
    int n3=20;
    cout<<totalMoney(n)<<endl;
    cout<<totalMoney(n2)<<endl;
    cout<<totalMoney(n3);
    return 0;
}