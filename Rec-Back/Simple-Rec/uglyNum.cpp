// LC - 263 - Easy - Ugly Number
// Rec - Maths
#include<iostream>
using namespace std;
bool isUglyRec(int n){
    if(n==0) return false;
    if(n==1) return true;
    
    if(n%2==0) return isUgly(n/2);
    if(n%3==0) return isUgly(n/3);
    if(n%5==0) return isUgly(n/5);
    return false;
}
bool isUgly(int n){
    while(n>1){
        if(n%2==0) n/=2;
        else if(n%3==0) n/=3;
        else if(n%5==0) n/=5;
        else return false;
    }
    return n==1;
}
int main(){
    // Output: true
    int n=6;
    // Output: true
    int n2=1;
    // Output: false
    int n3=14;
    cout<<isUglyRec(n)<<endl;
    cout<<isUglyRec(n2)<<endl;
    cout<<isUglyRec(n3);
    return 0;
}