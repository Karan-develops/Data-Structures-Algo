#include<iostream>
#include<cmath>
using namespace std;
int binToDec(int n){
    int ans=0;
    int i=0;
    while(n>0){
        int bit=(n&1);
        ans+=bit*pow(2,i++);
        n=n/10;
    }
    return ans;
}
int main(){
    short n;
    cout<<"Enter a binary number:";
    cin>>n;
    cout<<"The decimal representation of "<<n<<" is: "<<binToDec(n);
    return 0;
}